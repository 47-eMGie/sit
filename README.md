# SIT - show in table (CLI)

### What it's all about?
SIT is my amateur CLI project written in C++ that displays data from text file in table format. It distinguishes records by separator given in an argument, taken from user input or set as space by default.

### Usage in practice

Command (Linux/MacOS): `./sit test`

Text file (test):

``` text
NAME SURNAME OCCUPATION
Mike XYZ teacher
Laurel XZY carpenter
Mathew ZYX artist
```

Output:

``` text
-----------------------------------------
| NAME       | SURNAME    | OCCUPATION  |
-----------------------------------------
| Mike       | XYZ        | teacher     |
-----------------------------------------
| Laurel     | XZY        | carpenter   |
-----------------------------------------
| Mathew     | ZYX        | artist      |
-----------------------------------------
```

### Installation
You will have two executable files:

`sit` - for Linux/MacOS

`sit.exe` - for Windows system

You don't need both. Choose the one that matches your operating system and run it as shown in next section. You can delete other one without any consequences.

### How to use it?
#### Linux/MacOS

``` bash
./sit arg1 arg2
```

#### Windows

``` powershell
sit.exe arg1 arg2
```

---

##### Where

`arg1` - name of the file.

`arg2` - (optional) - separator character. If not given, separator will be set to space.

---
If second argument will have more than one character only first one will be set as separator.

If no argument will be given, user prompt will be displayed to ask about name of the file and separator (here defining separator is optional too).

---
Tested only on Windows and Linux platforms
