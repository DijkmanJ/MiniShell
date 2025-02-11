# Minishell

Minishell is a **42 School** project that involves creating a simplified Unix shell in C. This project replicates fundamental behaviors of the Bash shell, allowing users to execute commands, manage processes, and handle input/output redirection.

## Features

- Display a prompt and wait for user input
- Parse and execute commands using `fork` and `execve`
- Handle built-in commands:
  - `echo` (with `-n` option)
  - `cd`
  - `pwd`
  - `export`
  - `unset`
  - `env`
  - `exit`
- Support for command execution with full path resolution
- Input and output redirection (`<`, `>`, `>>`)
- Pipes (`|`) for command chaining
- Environment variable expansion (`$VAR`)
- Signal handling (Ctrl+C, Ctrl+D, Ctrl+\)
- Error handling and memory management

## Installation

```sh
git clone https://github.com/DijkmanJ/minishell.git
cd minishell
make
```

## Usage

Run the shell by executing:
```sh
./minishell
```

## Example

```sh
$ ls -l | grep minishell > output.txt
$ cat output.txt
-rwxr-xr-x 1 user user 123456 Feb 11 12:34 minishell
$ echo "Hello, world!"
Hello, world!
```

## Requirements

- GNU Make
- GCC
- Linux or macOS

## Project Guidelines

This project follows the **42 School** rules:
- No use of `printf`, `malloc`, or `free` from standard libraries.
- Restricted use of global variables.
- Memory leaks must be prevented.

## License

This project is licensed under the **MIT License**.



