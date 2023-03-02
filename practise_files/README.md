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
## Exercises
### 0. getppid
This source code returns the same value as the return value of the shell
command `echo $$` because the program is a child process of the shell.

### Read line

To read the enitre line inputted by a user in standard input, you use
`getline()` which is defined with this prototype:

```C
#include <stdio.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);
```
where `ssize_t` and `size_t` are `signed` and `unsigned` integers.
- `n` is a pointer to an unsigned integer
- `lineptr` is a pointer to a pointer 

`getline()` reads an entire line from 
[stream](https://www.gnu.org/software/libc/manual/html_node/Standard-Streams.html)
and stores the address to the buffer(memory location) containing the text into
`*lineptr`. The text in the buffer is null-terminated and includes the newline
character, if one is found.


if you set `*lineptr` to `NULL` and `n` to $0$ before the call, then
`getline()` will allocate a buffer for storing the line. The buffer should be
freed by the user program even if `getline()` failed.

```C
#include <stdio.h>

int main(void)
{
	ssize_t nread;
	char *lineptr = NULL;
	size_t n = 0;

	nread = getline(&lineptr, &n, stdin);
	if (nread != -1)
	{
		printf("%s\n", lineptr);

	}
	else 
	{
		perror("Unable to read line\n");
	}

	return 0;
}

```

On successful execution, `getline()` returns the number of characters read
including delimiter characters, but not including the terminating null byte
('\0')

`getline()` returns $-1$ on failure to read a line (including end-of-file
condition)

Alternatively, before calling `getline()`, `*lineptr` can contain a pointer to
a malloc allocated buffer of size `*n` bytes. If the buffer size `*n` bytes
that you specified is not large enough to hold the line, `getline()` resizes
it with `realloc()`, updating `*lineptr` and `*n` as necessary.

Because `getline()` has the ability to reallocate memory for the buffer depending on the
amount of bytes it reads, the address of `lineptr` and `n` are passed as
argument to `getline()`. The values are updated accordily.
