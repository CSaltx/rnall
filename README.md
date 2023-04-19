## Rnall: A New Coreutil

### A module built to optimize your workflow

<div align="center">
  
  ![C](https://img.shields.io/badge/c-%2300599C.svg?style=for-the-badge&logo=c&logoColor=white)
  ![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
  ![Ubuntu](https://img.shields.io/badge/Ubuntu-E95420?style=for-the-badge&logo=ubuntu&logoColor=white)
  ![Shell Script](https://img.shields.io/badge/shell_script-%23121011.svg?style=for-the-badge&logo=gnu-bash&logoColor=white)
  
</div>

## Table of Contents

- [General Project Information](#general-project-information)
- [Introduction](#introduction)
- [Information](#information)
- [Usage](#usage)
- [Technologies](#technologies)

### General Project Information

**Title:** Operating Systems Project - rnall <br/>
**Department:** Computer Science

**Name:** Coby Schumitzky<br/>
**Name:** Aaron Floreani<br/>
**Name:** Shaun Seah<br/>
**Name:** Ryan Nguyen<br/>
**Date:** 4/19/2023

**Course:** Operating Systems<br/>
**Section:** CMSI 3510

### Introduction

Everyone makes typos.

As a programmer or general computer user, there has been or will come a time when you want to alter the names of a file or multiple files. In the past, there has been the rn (rename) command but this is not inherent on Linux or in the Coreutils. Additionally, you cannot rename mulitple files using rn and thus, you will find a massive decrease in efficiency with this. As a result, there have been iterations such as the Debian Perl version of the rename command but we still saw a problem and an issue to solve. For this, we made rnall (short for rename all), a coreutil that uses mostly base C code along with a few header files to incorporate mass renaming capabilities to any linux system.

### Information

This new module allows a user to change multiple filenames using a single command. Imagine a scenario where you are creating a OOP project and wanted to create some files for each class but decided to name them test in the meantime:
```bash
>>> sudo touch test1 test2 test3
```
Now after creating the project and testing, you want to push to production but with these filenames, it wouldn't be very professional. So you decide to make it better. It wouldn't be very efficient to rename each file individually or worse move the contents of each file to a new one. Well now you can do it with a single command using rnall.

**_NOTE:_** See install.md for information on how to download and install. See Usage for information on formatting.

### Usage
  
  ```py
    rnall <format_1> <format_2> <directory_path (optional)>
  ```

---

### Technologies

Project was created with:

- C v17
- GCC v13.1
- Ubuntu v22.10
- GNU Coreutils
- UTM v4.0.9
