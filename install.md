# Installation Guide
### Note this is a general guide and may not work on some machines
**_NOTE:_** Machine used in testing was a UTM vm running Ubuntu v22.10 on a MacOS machine running Ventura 13.0 with an Apple Silicon Processor

## Read Steps Below and Follow Them for Successful Installation

- First you need to download the base coreutils from <a href="https://github.com/coreutils/coreutils">GitHub</a> <br/>
- CD into this new folder and ./bootstrap
  - if this does not work you may need to install some dependencies such as running:
    ```sh
      sudo apt install autoconf automake autopoint bison gperf texinfo -y
    ```
    with these dependencies installed, you should be able to run ./bootstrap
- Now run:
  ```sh
    ./configure --quiet #[--disable-gcc-warnings] [*] && make && make check
  ```
  This should make the coreutilties and should leave you without warnings
  
- Now download the file rnall.c in this repository <a href="https://github.com/CSaltx/rnall/blob/main/rnall.c">here</a>.
- We will assume you downloaded into a downloads folder but remember the path as it will be necessary, if possible download into coreutils/src
- If you did not download into coreutils/src past this into your terminal:
  ```sh
    cp [directory path to rnall.c] [directory path to coreutils/src]
  ```
  replace these information in the square brackets with the related path
- Now assuming rnall.c is within your 'src' folder, run this command:
  ```sh
    gcc rnall.c -o rnall
  ```
  if gcc is not installed follow the information in the next step and come back to this step
- if GCC is not installed, run
  ```sh sudo apt install gcc```
- You should now see a file named 'rnall' in your coreutils/src folder
- To make this working globally you essentially have 2 options: 
  - copy the file into the correct folder to be able to use it globally
    ```sh
      cp rnall /usr/local/bin/
    ```
    Now you can run rnall globally but remeber you must use it with the sudo prefix unless you want to give it root access rights which you can do with this command
    ```sh
      sudo chmod +x /usr/local/bin/rnall
    ```
  -  Otherwise, you can run:
     ```sh
      make clean
      make install
     ```
     
     To ensure it worked correctly run:
     ```sh
      ls -l rnall
     ```
     and you should see
     ```sh
      -rwxr-xr-x 1 user user 123456 [current-date] rnall
     ```
     If this fails, try and do the first option and see if that works
