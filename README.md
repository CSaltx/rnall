## Rnall

### A NEW LINUX COREUTIL

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
- [Installation and Usage](#installation)
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

Have you wanted a command to rename multiple file names using a single command? Now you can with the “rnall” command, which is short for "rename all".

### Information

This new linux coreutil allows for matching different patterns in file names and replacing them with the desired string or pattern. 

**_NOTE:_** See Documentation section for information on how to download and run locally.

### Installation

<details><summary><b>Show instructions for installation</b></summary>
  <br/>
First, Click Code on main repo page to get HTTPS or SSH url and then open personal terminal (for this demonstration we will use Mac terminal) <br />
  
<br />In your terminal (Mac Terminal as example): <br />
1. Clone repo

```sh
  $ git clone {enter url here}
```

2. CD into folder

```sh
  $ cd gamedev
```

3. If using VSCode with adequate setup, otherwise skip:

```sh
  $ code .
```

> **_NOTE:_** the API key was used in a .env file and was not added to the GitHub Repository for security purposes so you must make an API key with RAWGApi to run and ensure that it is setup using the requisite .env file.

</details>

<details><summary><b>Show Instructions for Usage</b></summary>
  
  ```sh
    rnall <regex_1> <regex_2> <directory_path (optional)>
  ```
  
</details>

---

### Technologies

Project was created with:

- Node version: 19.1.0
- React version: 18.2.0
- React Router version: 6.4.4
- Firebase version: 9.14.0
