#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <regex.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3 || argc > 4) {
        printf("Usage: %s regex_one regex_two [directory_path]\n", argv[0]);
        return 1;
    }
    
    regex_t regex;
    if (regcomp(&regex, argv[1], REG_EXTENDED)) {
        printf("Invalid regular expression: %s\n", argv[1]);
        return 1;
    }
    
    char *directory_path = (argc > 3) ? argv[3] : ".";
    
    DIR *dir = opendir(directory_path);
    if (dir == NULL) {
        printf("Could not open directory: %s\n", directory_path);
        return 1;
    }
    
    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        if (regexec(&regex, entry->d_name, 0, NULL, 0) == 0) {
            char *oldname = entry->d_name;
            char *newname = malloc(strlen(oldname) - strlen(argv[1])+strlen(argv[2]));
            if (newname == NULL) {
                printf("Error allocating memory.\n");
                closedir(dir);
                regfree(&regex);
                return 1;
            }
            sprintf(newname, "%s", oldname);
            regmatch_t match;
            while (regexec(&regex, newname, 1, &match, 0) == 0) {
		 int match_start = match.rm_so;
		 int match_end = match.rm_eo;
		 int prefix_len = match_start;
		 int suffix_len = strlen(newname) - match_end;
		 int new_len = prefix_len + strlen(argv[2]) + suffix_len + 1;
		 char *newname2 = malloc(new_len);
		 if (newname2 == NULL) {
			printf("Error allocating memory.\n");
			free(oldname);
			closedir(dir);
			regfree(&regex);
			return 1;
		 }
		 strncpy(newname2, newname, prefix_len);
	     	 strcpy(newname2 + prefix_len, argv[2]);
     		 strcpy(newname2 + prefix_len + strlen(argv[2]), newname + match_end);
		 newname2[new_len - 1] = '\0';
		 free(newname);
		 newname = newname2;
		 match.rm_eo = match_start + strlen(argv[2]); // update ending positionmatch.rm_eo = match.rm_so + len;
            }
            char *oldpath = malloc(strlen(directory_path) + strlen(oldname) + 2);
            if (oldpath == NULL) {
                printf("Error allocating memory.\n");
                closedir(dir);
                regfree(&regex);
                return 1;
            }
            sprintf(oldpath, "%s/%s", directory_path, oldname);
            char *newpath = malloc(strlen(directory_path) + strlen(newname) + 2);
            if (newpath == NULL) {
                printf("Error allocating memory.\n");
                free(oldpath);
                closedir(dir);
                regfree(&regex);
                return 1;
            }
            sprintf(newpath, "%s/%s", directory_path, newname);
            if (rename(oldpath, newpath) != 0) {
                printf("Error renaming file: %s\n", oldpath);
            }
            free(oldpath);
            free(newpath);
            free(newname);
        }
    }
    
    closedir(dir);
    regfree(&regex);
    return 0;
}
