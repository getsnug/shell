# Oh My Shell
Oh My Shell (OMS) is a custom shell built with C. OMS is strongly based on unix and the commands are much the same.

OMS is a 20 Percent Project built for a Post-AP Computer Science class at the Kent Denver School. It is still be developed (as of 12/24/2018) by Ulysses Atkeson '19 and Vaughn Ramsey '20.

Both of us are fairly new to C and thus there were and still are a fair amount of errors and bad practices in our code. This project was meant to be an exploration in C and deep level OS rather than a product that people should use. See our writeup [here](https://docs.google.com/document/d/1r5wFiNTjW0K_m928dFGG65cE2dXGZLB1AMDnsoKNAlg/edit?usp=sharing)

## Files
### README.md
This file.
### bash.c
The main file that runs all other files and commands. This file is the biggest and thus it might contain errors.
### cd.c
The file that runs the cd command. cd changes the working directory. This file also proved the most tricky to implement and thus it might contain errors.
### cd.h
The header file for the cd.c file
### ls.c
The file that runs the ls command. ls returns all of the items in the working directory.
### ls.h
The header file for the ls.c file
### mkdir.c
The file that runs the mkdir command. mkdir creates a new directory in the working directory.
### mkdir.h
The header file for the mkdir.c file
### touch.c
The file that runs the touch command. touch creates a file in the working directory.
### touch.h
The header file for the touch.c file

## Commands
The commands we have implemented so far are:
cd, ls, mkdir and touch

## Installation
One of the hardest things about this projects was finding an environment to run, test and collaborate on. While we could have use a local machine, we wanted the ability to easily work on the code at the same time. Because of this we decided to use a remote machine. While there are cheaper options, we chose to use Google Cloud VM Instances because we had a lot of credit to use the service.

### Pre Requirements
* Access to a computer and the internet
* A google account
* Credit to Google Cloud Services OR a linked funding source
* Some knowledge of computers and computer science (helpful but not required)

### Google Cloud VM Instances Setup
Use [this](https://cloud.google.com/compute/docs/instances/create-start-instance)
* for the OS choose ubuntu 14

### Install Code
Note you will most likely need to run sudo in front of any command you want to use
* SSH in via the website or via the ssh command in terminal
* `git clone https://github.com/getsnug/shell.git`

If you want gdb
* `sudo apt-get update`
* `sudo apt-get install gdb`
