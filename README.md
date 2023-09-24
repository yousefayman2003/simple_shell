<h1 align=center> Unix-like Simple Shell Project </h1>
<p align=center>
  <img height=500 src="https://www.juliensobczak.com/posts_resources/2021-08-10-linux-system-calls-under-the-hood/system-calls.png"/>
</p>

## Introduction
This is a Unix-Like Simple Shell project, developed by [Mohammed Mustafa](https://www.linkedin.com/in/mohammedmustafa112025/) and [Yousef Ayman](https://www.linkedin.com/in/yousef-ayman/) using C system calls. It provides a basic command-line interface for interacting with the operating system.
The shell allows you to execute various commands and perform operations similar to a traditional Unix shell.
We are proud to share that our simple shell implementation is memory leak-free, demonstrating our commitment to producing high-quality code.
We prefered to reimplement most of built-in functions that we need it in the project.


## Features

1. **Command Execution**: The shell supports executing commands entered by the user. It can run both built-in commands and external programs.
2. **Built-in Commands**: The shell provides a few built-in commands that can be executed directly within the shell, such as `cd` (change directory), `env` (print session's environment variables), `setenv` (add an evnironment variable to session's env), `unsetenv` (remove an evnironment variable to session's env), `echo` (print text, exit status of latest executed program, current pid, and etc), and `exit` (terminate the shell).
3. **Command Line Parsing**: The shell parses the command line input and separates the command from its arguments, allowing for the execution of commands with arguments and options.
4. **Path Resolution**: The shell resolves the full path of external programs based on the directories listed in the `PATH` environment variable.
5. **Command Comments**: The shell supports command comments using the `#` operator.
6. **Piping**: The shell supports command piping using the `|` operator. This allows you to chain multiple commands together, where the output of one command is used as the input for the shell.

## Getting Started

1. Clone the repository: `git clone https://github.com/your-username/simple-shell.git`
2. Change to the project directory: `cd simple_shell`
3. Compile the shell program: `gcc *.c -o shell`
4. Run the shell: `./shell`

## Usage

Once the shell is running, you can enter commands and interact with the system. Here are some examples:

- Execute a command: `ls -l`
- Execute a command with full path of external programs: `/bin/whoami`
- Change directory: `cd /path/to/directory`
- command with comments: `exit 98 #exit the program with 98 exit status`
- Pipe commands: `echo env | ./hsh`

To exit the shell, you can use the `exit` command or press `Ctrl + C`.

## Limitations

This simple shell project has some limitations:

1. No advanced features: The shell doesn't support advanced features like shell scripting.
2. Limited error handling: Error handling is minimal, and error messages may not always be descriptive.
3. Limited command support: Only a few built-in commands are supported, but you can use all commands that its executabe files is in any of the PATH direcotries.
4. Basic command line parsing: The shell assumes simple command structures and may not handle complex command lines or special characters correctly.

## Contributing

Contributions to the project are welcome! If you have any ideas, improvements, or bug fixes, please submit a pull request with your changes.
Make sure to follow the project's coding style and conventions.

## Acknowledgments

The Unix-Like Simple Shell project is powered by Mohammed Mustafa and Yousef Ayman. Special thanks to ALX and the Holberton for their support and resources.
