# Mini-DataBase
## Contributing [![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/duttabhishek32/Mini-DataBase/issues)
Mini-DataBase is a simplified data base, written in C++.It is made for the purpose of understanding the underlying details of File Management in OOP with C++.

# Functionality:
1. Add a member
2. Show all members
3. Save to file
4. Show members present in the file
5. Search for members in the file
6. Remove an entry from the file.

# Information about the member:
1. Name(Initials + Title)
2. Age
3. Phone Number

### Compile:
To compile the file you need 5 Libraries, which are built-in C++.
* iostream
* fstream
* conio.h
* cstdlib
* stdlib.h(in case of Turbo)

On g++(9.3.0 and above), the whole folder can be imported in the IDE(VScode,Sublime). Same goes for MinGW.
To run it, you need a global environment  variable "HOME" set, the data will be stored at $HOME/Mini-DataBase".

On your terminal(for Linux Distro)
```
g++ database.cpp
./a.out
```
For Command Prompt(Windows)
```
gcc database.cpp -o database.exe
database.exe
```
*You can find the information which will be saved in database.txt file.
### Unimplemented Features:
* Table Management
* Data Manipulation(Change the phone number of an existing member)
* Help in database
* Concatenate two entries
* User Management


