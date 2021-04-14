# PES1201800410 -- Prashanth A R 
### linux commands
#### 1. grep
- prints the line which match the patterns
```sh
$ grep -i -r "regex or pattern" filename
```
- -i  -- case-insensitive
- -r  -- recursive search (search all the files inside all the directory)

```sh
$ grep -m 5 "regex" filename
```
- -m number -- stop after max "number" of matches
- here it will stop after finding max of 5 search matches

#### 2. find
- search for files in a directory hierarchy

```sh
$ find . -type "f" -size -4K -delete
```
- -type -- type = file only (NOT directory)
- -size -- size of the file
- -4k --  "-"  indicates less than 4 kB in size
- -delete -- delete the found files

```sh
$ find . -iname "filename"
```
- -iname -- search for files with name "filename"
- -i indicates case-insensitive search

#### 3. netstat

- print network connections , ip tables info and many more

```sh
$ netstat -at
```
- -a -- print all connections
- -t -- filter all tcp ports  

```sh
$netstat -lu
```
- -l -- list only the listening ports
- -u -- filter all udp ports

#### 4. locate
- find files by name
- it is similar to find but super fast bcz it searches on database rather than on disk
- as database is not updated very frequently it may give outdated results
- we can update the db by doing "updatedb"

```sh
$ locate -e "filename"
```
- -e print the files only if it is existing at the current time of run

```sh
$ locate -i -l 5 "filename"
```
- -i search for case insensitive
- -l limit , stop search after l (limit) number is reached

#### 5 . ps
- report a snapshot of the current processes

```sh
$ ps -aux
```
- print all the process  

```sh
$ ps -ejH
```
- print all the process tree

### Make file Programme
<img src="https://github.com/prashanthar2000/cryptography_lab/raw/master/oslab1.png" width=1000 >

### Answer the following question

#### 1. Why do we use Make file
-  make file is a very intelligent way of compiling source program
-  It is very tiring to compile every source code very time manually
- make file only complies the files which are modified from the last compile .


#### 2 . Is Makefile a shell script?
- no makefile is a shell script
- it has its own way of using shell
- although we can all shell commands in make file

#### 3 .What does “clean” do in Makefile?
- clean is just a target in  make file
- it is generally used to clean(remove all the complied files) . to create a clean new build

#### 4.How does make learn about the last modified files to be complied?

- it checks for the target if it exits it asks os for date and time of creation
- then checks for dependencies , if they exits asks os for date and time of creation if they match the target is up to date
- else it will re-do the commands specified
- if any of the dependencies is not found it sends an error

#### 5. What does Cflags in Makefile mean?
- Cflags is a makefile variable
- it is normally used to provide arguments when compiling

#### 6.  Why do we use -f option with make command?
- -f filename to specify the make file name
- by default make will look for the makefiles GNUmakefile, makefile, and Makefile, in that order.
