/* Example code for rnall, built off of shell command: find . -type f -name '* (*)*' -exec rename 's/ \([^)]*\)//g' {} + */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <regex.h>
#include <string.h>

void rename_file(char *filename, char *pattern, char *regex_str) {
    regex_t regex;
    int reti;
    char *new_filename = malloc(new_len + 1);;
    size_t new_len = 0;
    
    reti = regcomp(&regex, pattern, 0);
    if (reti) {
        fprintf(stderr, "Error compiling regular expression: %s\n", pattern);
        exit(EXIT_FAILURE);
    }

    new_len = strlen(filename);
    reti = regexec(&regex, filename, 0, NULL, 0);
    if (!reti) {
        regmatch_t matches[10];
        reti = regexec(&regex, filename, 10, matches, 0);
        if (reti == 0) {
            int i;
            int num_matches = matches[0].rm_eo - matches[0].rm_so;
            
            new_len = strlen(regex_str) + strlen(filename) - num_matches;

            strncpy(new_filename, filename, matches[0].rm_so);
            strcat(new_filename, regex_str);
            strcat(new_filename, filename + matches[0].rm_eo);
        }

        if (rename(filename, new_filename) == 0) {
            printf("Renamed %s to %s\n", filename, new_filename);
        } else {
            fprintf(stderr, "Error renaming %s\n", filename);
        }
    } else if (reti == REG_NOMATCH) {
        // doesnt match, skip
    } else {
        char msgbuf[100];
        regerror(reti, &regex, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Error matching regular expression: %s\n", msgbuf);
        exit(EXIT_FAILURE);
    }

    regfree(&regex);
    free(new_filename);
}

int main(int argc, char *argv[]) {
    DIR *dir;
    struct dirent *ent;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s pattern regex\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    dir = opendir(".");
    if (dir == NULL) {
        fprintf(stderr, "Error opening directory\n");
        exit(EXIT_FAILURE);
    }

    while ((ent = readdir(dir)) != NULL) {
        struct stat st;
        char *filename = ent->d_name;

        if (strcmp(filename, ".") == 0 || strcmp(filename, "..") == 0) {
            continue;
        }

        if (stat(filename, &st) == -1) {
            fprintf(stderr, "Error getting file status for %s\n", filename);
            continue;
        }

        if (S_ISDIR(st.st_mode)) {
            // recursive call on every dir
            char *args[] = { argv[0], argv[1], argv[2], filename, NULL };
            execv(args[0], args);
        } else if (S_ISREG(st.st_mode)) {
            rename_file(filename, argv[1], argv[2]);
        }
    }

// Clean up
    closedir(dir);
    return 0;
}
