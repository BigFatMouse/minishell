# Minishell

This is two-person project. The objective of this project is to create a simple shell. Like little bash or zsh. In this project we learn about processes and file descriptors.

<h3>Available options</h3>

Minishell runs executables from an absolute, relative or environment PATH (/bin/ls or ls), including arguments or options. ' and " work the same as bash, except for multiline commands.

You can use redirections > >> < << and pipes |.

Environment variables are handled, like $HOME, including the return code $?.

Finally, you can use Ctrl-C to interrupt and Ctrl-\ to quit a program, as well as Ctrl-D to throw an EOF, same as in bash.

A few of the functions are "built-in", meaning we don't call the executable, we re-coded them directly. It's the case for echo, pwd, cd, env, export, unset and exit.


<h3>To run project:</h3>

- git clone https://github.com/BigFatMouse/minishell.git
- cd minishell
- make
- simply run it with : ./minishell
