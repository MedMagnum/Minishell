Minishell is a 1337 | 42 school project that involves reimplementing a "mini" bash terminal. In this project, I've re-implemented the following built-in functions:

'echo' (with '-n' option)
'cd' (with relative or absolute path)
'pwd' (without options)
'export' (without options)
'unset' (without options)
'env' (without options or arguments)
'exit' (without options)
I've also had to reimplement the following features :

Redirections (in and out to a file)
Multi commands with pipes
Manage the environment variables : you can use the '$' with 'echo' or in your redirections to print environment variables.
Handling signals : 'ctrl-c' and 'ctrl-d'
