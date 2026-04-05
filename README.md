[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/5ZUS_Sru)
# IT 2009 - Operating Systems
## Project 1: Implement a Shell

Deadline: May 3rd, 2026, 23:59
---

The purpose of this project is to familiarize you with the mechanics of process control through
the implementation of a **shell user interface in the C programming language**. This includes
the relationship between *child and parent processes*, the steps needed to *create a new process*,
*shell variables*, and an introduction to *user-input parsing and verification*.

---

### Task 1: Shell Interface

The **shell (command line)** is just a program that continually asks for user input, (potentially)
does something on the user's behalf, resets itself, and again asks for user input. In this task, you
need to **design and implement a basic shell interface** that supports the **execution of
other programs** and a **series of built-in functions**. The shell should be **robust** (e.g., it
should not crash under any circumstance beyond machine failure).

When you start the shell (by running its executable in the terminal), the prompt should look like
this:
```
machinename@username:~$
```

where **machinename** and **username** should change depending on the machine and user.
Moreover, choose a nice/interesting **name** for your shell (e.g. **aldinsh** - Aldin's Shell).

---

### Task 2: Shell Programs/Commands

Implement the basic functionality of the following *programs* (they should mirror/approximate
the functionality of these programs as found in UNIX systems):

- **echo**
- **date**
- **ls**
- **mv**
- **touch**
- **mkdir**
- **cd**
- **rm**
- **cp**
- **cat**
- **wc**
- **grep**

For example, the output of the `ls` command (list files and folders) would be something like
this:
```
machinename@username:~$ ls
Applications    Projects    Documents    Library
Music           Public      new_file.txt code.c
```

If a user tries to run a non-existent command, they should see an **appropriate error
message** (but the *shell itself* should **not crash**).
```
machinename@username:~$ non_existing_command
aldinsh: command not found: non_existing_command
```

The commands **echo**, **cat**, **touch** and **one more command of your choice** have to be
**implemented from scratch** in C (in total, **4 "custom" implementations**). The other
commands should execute *existing UNIX programs* (e.g., ls, grep, wc) using **fork()** and **exec()**
rather than implementing them from scratch.

Moreover, you need to provide **flags/argument support** for **at least three** of the programs
(e.g. the `-l` option for `ls`, or `-r` flag for `rm`). For example (adding `-l` flag to `ls`):
```
machinename@username:~$ ls -l
total 8
drwxr-xr-x@   7 aldin-sxr  staff    224 Feb 26 11:10 Applications
drwx------+   9 aldin-sxr  staff    288 Mar 10 08:25 Documents
drwx------@  88 aldin-sxr  staff   2816 Mar 16 09:11 Library
drwx------+   4 aldin-sxr  staff    128 Mar  9 13:33 Music
drwx------+   4 aldin-sxr  staff    128 Feb 20 11:38 Public
drwxr-xr-x+   4 aldin-sxr  staff    128 Feb 20 11:38 Projects
-rw-r--r--    1 aldin-sxr  staff    135 Mar  9 10:13 new_file.txt
-rw-r--r--    1 aldin-sxr  staff    135 Mar 10 13:15 code.c
```

You need to implement **at least two flags** for **one of** your *custom programs* (echo, cat, touch,
your fourth chosen command), while the **other two flag implementations** should be for the
*underlying UNIX programs* using fork/exec. For those programs, you only need to pass
arguments to the underlying UNIX program rather than reimplementing its internal
functionality.

Lastly, it should be possible to **pipe (`|`) output to another command** or **redirect (`>`)
output** to a **text file** for **at least one** of your **custom programs** (which support text output).
You *do not need* to implement pipe/redirection for re-used UNIX programs. For example:
```
machinename@username:~$ echo "hello" > out.txt
```

redirects the output of the `echo` command (`"hello"`) to a new text file called `out.txt`.

---

### Implementation and Submission Details

The shell should be implemented in the **C programming language**. Any implementations in
other languages, no matter how good, will be **immediately graded with 0 points**.

You are allowed to use **any online resources** to help you complete this project, **including AI
tools**. However, during the project defense (in Week 14 / study week), you are responsible for
understanding **every single line of code** that you have submitted. In the defense, you can
expect **detailed questions** about your code and implementation choices, and **potentially
make adjustments** to your code. During the defense, you **will not be allowed** to use **any
additional offline or online resources**.

The main purpose of this project is for you to **understand** how the shell and inter-process
communication and creation works, not "just" to implement everything without any deeper
understanding. Therefore, during the defense, what will be graded is your **understanding** of
the project, and the ability to **answer questions** and **provide explanations** about **your
code**. Furthermore, you may be asked to **modify or extend** your shell implementation
without using external resources. Therefore, you must **fully understand every part** of your
code.

There are **no tests** for the project, so
please do not send emails asking if your project is "passing tests" or not. GitHub Classroom is
only used as a means of **collecting all your projects** in a single place.

The deadline for the assignment is the **end of Week 9: May 3rd, 23:59**. Any submissions to
GitHub Classroom past this deadline **will not be accepted**.

*Good luck!*
