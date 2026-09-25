# Lab 0 — Environment Setup, Linux Commands, SSH and Git/GitHub

> **Format:** self-study before Session 1 (about 90–120 minutes). The first 30 minutes of Session 1 are reserved for checking the setup and helping anyone who is stuck.
> Part 5 (Git/GitHub) is **optional**, but recommended: submitting later labs through GitHub is much easier.

## Objectives

After this lab you will be able to:

- Work in a Linux environment with `gcc`, `gdb`, `make`, `valgrind` and VS Code.
- Use basic Linux commands to navigate the file system and manage files and directories.
- Compile and run your first C program from the command line.
- Connect to a remote server with SSH and copy files with `scp`.
- (Optional) Use Git to save your work and submit it to GitHub.

---

## Part 1. Setting up the environment

Choose **one** option that matches your computer.

### Option A — Windows: WSL2 + Ubuntu

WSL (Windows Subsystem for Linux) runs a real Ubuntu system inside Windows.

1. Open **PowerShell as Administrator** (right-click the Start button → *Terminal (Admin)*) and run:
   ```powershell
   wsl --install -d Ubuntu-24.04
   ```
2. Restart the computer. Open **Ubuntu** from the Start menu and choose a username and password. While typing the password, nothing appears on the screen — this is normal.
3. Inside Ubuntu, install the tools:
   ```bash
   sudo apt update
   sudo apt install -y build-essential gdb valgrind git
   ```
4. Install [VS Code](https://code.visualstudio.com/) on Windows, then install the extensions **WSL** and **C/C++ Extension Pack**.
5. From the Ubuntu terminal, type `code .` to open VS Code connected to WSL.

> Your Ubuntu home directory (`/home/<name>`) is visible in Windows Explorer at `\\wsl$\Ubuntu-24.04\home\<name>`.
> Keep your code **inside** Linux (`~/...`), not under `/mnt/c/...` — the Windows drive is much slower from WSL.

### Option B — Ubuntu / Linux

```bash
sudo apt update
sudo apt install -y build-essential gdb valgrind git
```

Install VS Code and the **C/C++ Extension Pack** extension.

### Option C — macOS

```bash
xcode-select --install     # installs clang, make, git, lldb
```

On macOS the `gcc` command is actually `clang`, which works fine for this course. However, `gdb` and `valgrind` do **not** run on Apple silicon Macs (M1/M2/…). For Sessions 2–3 (debugging and memory checking), Mac users should work on the **lab Linux server via SSH** (Part 4), or use `-fsanitize=address` (AddressSanitizer) instead of valgrind.

### Verify the installation

```bash
gcc --version
gdb --version
make --version
valgrind --version     # (not available on macOS)
```

Each command must print a version number, not `command not found`.

---

## Part 2. Basic Linux commands

You will spend the whole course in the terminal, so it is worth learning these commands well. Type every example yourself — do not copy and paste.

### 2.1. Anatomy of a command

```
gcc   -Wall -o hello   hello.c
───   ──────────────   ───────
command   options      arguments
```

- The **command** is the program to run.
- **Options** (also called flags) change its behaviour. They start with `-` (short form, e.g. `-l`) or `--` (long form, e.g. `--all`). Short options can be combined: `ls -l -a` is the same as `ls -la`.
- **Arguments** are what the command works on: file names, directories, text.
- Linux is **case-sensitive**: `Hello.c` and `hello.c` are two different files, and `LS` is not a command.

**Getting help:**

```bash
man ls          # full manual page; use ↑/↓ to scroll, / to search, q to quit
ls --help       # short summary of the options
whatis ls       # one-line description
```

### 2.2. The file system and paths

Linux has a single directory tree that starts at the **root** `/`:

```
/
├── bin/            system programs (ls, cp, ...)
├── etc/            configuration files
├── usr/            installed software and libraries (/usr/include/stdio.h lives here)
├── tmp/            temporary files
└── home/
    └── an/         ← your home directory, also written as ~
        └── prog1/
            ├── lab00/
            └── lab01/
```

Special path names:

| Name | Meaning |
|---|---|
| `/` | Root of the file system |
| `~` | Your home directory (`/home/<name>`) |
| `.` | The current directory |
| `..` | The parent directory (one level up) |
| `-` | (with `cd` only) the previous directory |

- An **absolute path** starts with `/` and works from anywhere: `/home/an/prog1/lab00`.
- A **relative path** starts from the current directory: if you are in `/home/an`, then `prog1/lab00` means `/home/an/prog1/lab00`.

### 2.3. Navigating: `pwd`, `ls`, `cd`

**`pwd`** — *print working directory*: shows where you are.

```bash
$ pwd
/home/an
```

**`ls`** — *list* the contents of a directory.

```bash
$ ls                 # contents of the current directory
prog1  notes.txt
$ ls prog1           # contents of another directory
lab00  lab01
$ ls -a              # also show hidden files (names starting with .)
.  ..  .bashrc  .ssh  prog1  notes.txt
$ ls -l              # long format: one file per line with details
drwxr-xr-x 4 an an 4096 Sep 25 10:12 prog1
-rw-r--r-- 1 an an  120 Sep 25 10:15 notes.txt
$ ls -lh             # -h: human-readable sizes (4.0K, 1.2M instead of bytes)
$ ls -lt             # sort by modification time, newest first
$ ls *.c             # only files ending in .c (see wildcards, 2.9)
```

How to read a line of `ls -l`:

```
-rw-r--r--  1  an  an  120  Sep 25 10:15  notes.txt
│└──┬────┘     │   │   │    │             └ file name
│   │          │   │   │    └ last modified
│   │          │   │   └ size in bytes
│   │          │   └ group
│   │          └ owner
│   └ permissions (see 2.8)
└ type: - = regular file, d = directory, l = link
```

**`cd`** — *change directory*.

```bash
cd prog1            # go into prog1 (relative path)
cd /usr/include     # go to an absolute path
cd ..               # go up one level
cd ../..            # go up two levels
cd ~                # go home (plain `cd` does the same)
cd -                # go back to the previous directory
```

> Tip: press **Tab** after typing the first letters of a name and the shell completes it. Press Tab twice to see all possibilities. This saves time and avoids typos.

### 2.4. Creating, copying, moving and deleting

**`mkdir`** — *make directory*.

```bash
mkdir lab00                  # create one directory
mkdir src build docs         # create several at once
mkdir -p prog1/lab01/src     # -p: create missing parent directories too, no error if it exists
```

**`touch`** — create an empty file (or update the modification time of an existing one).

```bash
touch main.c utils.c utils.h
```

**`cp`** — *copy*.

```bash
cp main.c main_backup.c      # copy a file to a new name
cp main.c src/               # copy into a directory (keeps the name)
cp -r lab00 lab00_backup     # -r (recursive): copy a whole directory
cp -i main.c src/            # -i (interactive): ask before overwriting
```

**`mv`** — *move* or *rename* (it is the same operation in Linux).

```bash
mv main_backup.c old.c       # rename a file
mv old.c docs/               # move a file into a directory
mv lab00_backup archive      # rename a directory
```

**`rm`** — *remove* files.

```bash
rm old.c                     # delete a file
rm *.o                       # delete all object files
rm -i *.c                    # ask for confirmation for each file
rm -r archive                # -r: delete a directory and everything inside it
rmdir docs                   # delete an EMPTY directory
```

> **Warning:** there is **no recycle bin** in the terminal. A file deleted with `rm` is gone. Double-check before `rm -r`, and never run `rm -rf` on a path you have not read carefully.

### 2.5. Viewing files

**`cat`** — print the whole file (good for short files).

```bash
cat hello.c
cat -n hello.c               # -n: show line numbers
```

**`less`** — view a long file one screen at a time.

```bash
less /usr/include/stdio.h
```

Inside `less`: `Space`/`b` = next/previous page, `/printf` = search for "printf", `n` = next match, `g`/`G` = start/end of the file, `q` = quit.

**`head`** and **`tail`** — the first or last lines.

```bash
head hello.c                 # first 10 lines
head -n 3 hello.c            # first 3 lines
tail -n 5 output.txt         # last 5 lines
tail -f log.txt              # keep printing new lines as they are added (Ctrl+C to stop)
```

**`wc`** — *word count*.

```bash
$ wc hello.c
  7  15 105 hello.c          # lines, words, bytes
$ wc -l *.c                  # number of lines of each .c file, plus a total
```

### 2.6. Editing files in the terminal

VS Code is the main editor in this course (`code file.c`), but on a remote server you often only have a terminal editor. **`nano`** is the simplest:

```bash
nano hello.c
```

The shortcuts are shown at the bottom (`^` means Ctrl): `Ctrl+O` then Enter = save, `Ctrl+X` = exit, `Ctrl+K` = cut line, `Ctrl+U` = paste, `Ctrl+W` = search.

**`echo`** prints text; combined with redirection (2.7) it can create small files quickly:

```bash
echo "Hello"                         # print to the screen
echo "first line" > notes.txt        # create/overwrite a file
echo "second line" >> notes.txt      # append to a file
```

### 2.7. Redirection and pipes

Every program has three standard streams: **stdin** (input, normally the keyboard), **stdout** (normal output, the screen) and **stderr** (error messages, also the screen). You can redirect them.

| Syntax | Meaning | Example |
|---|---|---|
| `> file` | Send stdout to a file (overwrite) | `./hello > out.txt` |
| `>> file` | Send stdout to a file (append) | `./hello >> out.txt` |
| `< file` | Read stdin from a file instead of the keyboard | `./sum < input.txt` |
| `2> file` | Send stderr to a file | `gcc bad.c 2> errors.txt` |
| `&> file` | Send both stdout and stderr | `make &> build.log` |
| `cmd1 \| cmd2` | **Pipe**: the output of cmd1 becomes the input of cmd2 | `ls -l \| grep ".c"` |

Examples:

```bash
ls -l /usr/include > headers.txt     # save a directory listing to a file
wc -l < headers.txt                  # count its lines
ls /usr/include | wc -l              # same result with a pipe, no file needed
history | grep gcc                   # which gcc commands did I run?
echo "3 4" | ./add                   # give input to a program without typing it
```

> Input redirection is very useful for testing programs that read with `scanf`: write the test input once in `input.txt` and run `./program < input.txt` as many times as you like.

### 2.8. Searching: `grep` and `find`

**`grep`** — search for text *inside* files.

```bash
grep printf hello.c          # lines of hello.c containing "printf"
grep -n printf *.c           # -n: show line numbers
grep -i hello notes.txt      # -i: ignore upper/lower case
grep -r "main(" .            # -r: search recursively in all files below .
grep -c include hello.c      # -c: only count matching lines
grep -v "^$" hello.c         # -v: lines that do NOT match (here: non-empty lines)
```

**`find`** — search for *files* by name, type, etc.

```bash
find . -name "*.c"           # all .c files below the current directory
find ~/prog1 -name "lab*"    # names starting with "lab"
find . -type d               # only directories
find . -name "*.o" -delete   # find and delete all object files (careful!)
```

### 2.9. Wildcards

The shell expands wildcards into matching file names **before** running the command.

| Pattern | Matches | Example |
|---|---|---|
| `*` | Any sequence of characters | `ls *.c` → `hello.c main.c` |
| `?` | Exactly one character | `ls lab0?.c` → `lab01.c lab02.c` |
| `[abc]` | One of the listed characters | `ls lab0[12].c` → `lab01.c lab02.c` |
| `{a,b}` | Each alternative (brace expansion) | `mkdir -p proj/{src,build,docs}` |

### 2.10. Permissions and `sudo`

The first column of `ls -l` shows who can do what with a file:

```
-rwxr-xr--
 └┬┘└┬┘└┬┘
  │  │  └ others: r-- (read only)
  │  └ group:  r-x (read, execute)
  └ owner:     rwx (read, write, execute)
```

`r` = read, `w` = write (modify), `x` = execute (run a program / enter a directory).

```bash
chmod +x run.sh              # make a script executable
./run.sh                     # now it can be run
chmod 644 notes.txt          # rw-r--r-- (number form: r=4, w=2, x=1)
```

`gcc` sets the `x` permission on the programs it builds automatically, which is why `./hello` works.

**`sudo`** runs one command as the administrator (root). You need it to install software (`sudo apt install ...`). Do not use `sudo` for normal work such as compiling.

### 2.11. Processes

```bash
./program        # runs in the foreground; the terminal waits for it to finish
Ctrl+C           # stop (kill) the running program — use it when your program hangs in an infinite loop
Ctrl+D           # "end of input" (EOF) for a program reading from the keyboard
ps               # list your running processes
top              # live view of CPU/memory usage (q to quit)
kill 12345       # stop the process with ID 12345 (the PID from ps)
```

### 2.12. Installing software (Ubuntu / WSL)

```bash
sudo apt update              # refresh the list of available packages
sudo apt install tree        # install a package
tree ~/prog1                 # show a directory as a tree
```

### 2.13. Time-saving shortcuts

| Shortcut | Action |
|---|---|
| `Tab` | Auto-complete a command or file name (twice: show choices) |
| `↑` / `↓` | Previous / next command in the history |
| `Ctrl+R` | Search the command history (type part of a command) |
| `Ctrl+A` / `Ctrl+E` | Jump to the start / end of the line |
| `Ctrl+L` | Clear the screen (same as `clear`) |
| `!!` | Repeat the last command (e.g. `sudo !!`) |

### Exercise 2.1

Using **only the terminal**, do the following and record every command you use in the file `~/prog1/lab00/commands.txt` (hint: `history`).

1. Create the directory structure `~/prog1/lab00/practice/{src,build,docs}` with a single command.
2. In `practice/docs`, create a file `readme.txt` containing two lines, `Programming 1` and `Lab 0`, using `echo` and redirection.
3. Show the content of `readme.txt` with line numbers.
4. Copy `readme.txt` to `practice/src/notes.txt`, then rename it to `info.txt`.
5. List `practice` recursively (`ls -R`) and save the result to `practice/listing.txt`.
6. Use `find` to list all `.txt` files under `~/prog1`.
7. Use `grep` to find which files under `practice` contain the word `Lab`, with line numbers.
8. Count how many header files there are in `/usr/include` (only the top level) using a pipe.
9. Delete the `practice/build` directory, then rename `practice` to `practice_done`.

---

## Part 3. Your first C program

```bash
mkdir -p ~/prog1/lab00
cd ~/prog1/lab00
code hello.c        # or: nano hello.c
```

Contents of `hello.c`:

```c
#include <stdio.h>

int main() {
    printf("hello, world\n");
    return 0;
}
```

Compile and run:

```bash
gcc -Wall hello.c -o hello   # -Wall: enable warnings, -o: name of the output file
./hello                      # ./ means "the file hello in the current directory"
```

Split the **compile** and **link** steps as in Lecture 1:

```bash
gcc -c hello.c -o hello.o    # compile: .c -> .o (machine code, not runnable yet)
gcc hello.o -o hello         # link: .o + standard library -> executable
./hello
```

**Question:** remove the `;` after `printf(...)` and compile again. Which line does the compiler report? Read the error message and explain it.

### Exercise 3.1

1. Create `~/prog1/lab00/project/{src,build}` and copy `hello.c` into `project/src/`.
2. From inside `project`, compile so that the executable is placed in `project/build/` (hint: `gcc src/hello.c -o build/hello`).
3. Run the program and save its output to `project/output.txt`; then show the file.
4. Run `ls -l build/hello`. Which permission letters show that it is executable?
5. Append these commands to `commands.txt`.

---

## Part 4. SSH — working on a remote server

SSH (Secure Shell) opens a terminal on another machine over the network, for example the lab's Linux server.

> Your instructor provides: the server address `<server>`, your username `<user>` and an initial password.

### 4.1. Logging in

```bash
ssh <user>@<server>               # first time: answer "yes" to "Are you sure...?"
ssh -p 2222 <user>@<server>       # if the server uses a port other than 22
exit                              # log out (or Ctrl+D)
```

Once logged in, try `pwd`, `ls`, `gcc --version`, `whoami`, `hostname`.

### 4.2. Logging in with a key (no password)

```bash
ssh-keygen -t ed25519 -C "your_email@example.com"   # press Enter to accept the defaults
ls ~/.ssh                                           # id_ed25519 (private) and id_ed25519.pub (public)
ssh-copy-id <user>@<server>                         # copy your public key to the server
ssh <user>@<server>                                 # no password needed any more
```

> **Never** share the file `id_ed25519` (your private key). Only the `.pub` file may be shared.

### 4.3. A shortcut in `~/.ssh/config`

```
Host lab
    HostName <server>
    User <user>
    Port 22
```

Now `ssh lab` is enough.

### 4.4. Copying files

```bash
scp hello.c lab:~/                  # local -> server
scp lab:~/hello.c ./hello_copy.c    # server -> local
scp -r lab00 lab:~/prog1/           # copy a whole directory
```

### 4.5. VS Code Remote-SSH

Install the **Remote - SSH** extension, click the `><` icon in the bottom-left corner → **Connect to Host...** → choose `lab`. VS Code then edits files and opens terminals directly on the server.

### Exercise 4.1

1. Log in to the server with your password, then set up key-based login.
2. Copy `hello.c` to the server with `scp`, compile and run it there.
3. Run `uname -a` on the server and on your own machine and compare the results.

---

## Part 5 (optional). Git and GitHub

Git records the history of your code; GitHub hosts repositories online for submission, sharing and teamwork.

### 5.1. First-time configuration

```bash
git config --global user.name "Nguyen Van An"
git config --global user.email "your_email@example.com"
git config --global init.defaultBranch main
```

### 5.2. Add your SSH key to GitHub

```bash
cat ~/.ssh/id_ed25519.pub     # copy this whole line
```

On GitHub: **Settings → SSH and GPG keys → New SSH key** → paste it. Then check:

```bash
ssh -T git@github.com         # "Hi <name>! You've successfully authenticated..."
```

### 5.3. Fork and clone the course repository

1. Open the course repository on GitHub and click **Fork** to create your own copy.
2. Clone your fork:
   ```bash
   cd ~/prog1
   git clone git@github.com:<your_account>/cse-programming1.git
   cd cse-programming1
   ```
3. Also clone the reference examples used in the labs:
   ```bash
   cd ~/prog1
   git clone https://github.com/bonigarcia/c-programming.git
   ```

### 5.4. The daily workflow

```bash
git status                    # which files have changed?
git add labs/lab01/lab01.c    # stage a file for the next commit
git commit -m "Lab 1: exercises 1-3 done"
git push                      # upload to GitHub
git pull                      # download new changes from GitHub
git log --oneline             # show the history
git diff                      # show changes that are not staged yet
```

```
 Working directory --git add--> Staging area --git commit--> Local repo --git push--> GitHub
                  <------------------------------------------------git pull--------
```

### 5.5. `.gitignore`

Do not commit build outputs (`*.o`, executables). The course repository already has a `.gitignore`; for your own repositories, create one:

```
*.o
*.out
a.out
build/
```

### 5.6. Getting new material from the instructor into your fork

```bash
git remote add upstream https://github.com/<instructor_account>/cse-programming1.git
git pull upstream main
git push
```

### Exercise 5.1

1. Fork and clone the course repository.
2. Copy your `commands.txt` to `labs/lab00/commands.txt` inside the repository, then commit and push it.
3. Send the link to your fork to the instructor.

---

## Checklist before Session 1

- [ ] `gcc --version`, `gdb --version` and `make --version` work
- [ ] Exercise 2.1 done (`commands.txt`)
- [ ] `hello.c` compiles and runs (Exercise 3.1)
- [ ] You can log in to the server with SSH (if the class uses one)
- [ ] (Optional) You have a fork of the course repository on GitHub

## Further reading

- VS Code + C on Linux: https://code.visualstudio.com/docs/cpp/config-linux
- VS Code + WSL: https://code.visualstudio.com/docs/cpp/config-wsl
- The Missing Semester of Your CS Education (shell, Git): https://missing.csail.mit.edu/
- The Linux Command Line (free book): https://linuxcommand.org/tlcl.php
- Pro Git: https://git-scm.com/book/en/v2
