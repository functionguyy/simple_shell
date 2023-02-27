# Everything you need to know to start coding your own shell

> The files in this subdirectory contain practise source codes that we used to study
> in preparation to build our Unix-like simple shell software.

The subheading below links to files that give more context to there meaning


## PID & PPID
**PID** is acronym for process ID  while **PPID** is acronym for Parent Process ID.

A process is an instance of an executing program; it refers to a running instance of
a program. it is made up of the program instruction, data read from files,
other programs or input from a system user. 

There are fundamentally two types of processes in Linux

- Foreground process (interative process) - Processes that are initialized and
controlled through terminal session. This kind of process requires a user to
be connected to the system to start it. 

- Background process(non-interactive process) = Processes that are not
connected to a terminal; they start automatically without user input.

Once you run a command or program, it will start a process in the system.

> A running instance of a program or command is indentified by its process ID
> (PID) as it's parent process ID (PPID)

- Parent process - process that create other processes during run-time.
- Child process - process that is created by other processes during run-time.

A child process will have the same properties/enviroment as its parent, but
a different process ID number.

You use the following functions defined by these prototypes below to get the
process ID and parent process ID of a calling process
```C
#include <sys/types.h>
#include <unistd.h>

pid_t getpid(void);  // To get the process ID of the calling process

pid_t getppid(void);  // To get the parent process ID of the calling process

```
These functions don't return any errors.
