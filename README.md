# cpu_tester

**cpu_tester** is a simple command-line tool designed to validate the 
execution of an executable on a specific CPU. It provides information 
about the process ID (pid) and the CPU on which it is running.

## Usage

To use **cpu_tester**, follow the syntax below:

```
$ ./cpu_tester <seconds>
```

The <seconds> parameter should be an integer representing the number 
of seconds the utility should wait before spawn a new message.

## Output

Upon execution, cpu_tester will display the following messages on the 
standard output:

```
[pid] CPU alive tester
[pid] Process is allowed to run on the following CPUs:
[pid] CPU 0
[pid] CPU 1
...
[pid] CPU n
[pid] Sleeps for <seconds> second(s)
[pid] Current CPU: <cpu_number>
```

The output will indicate th pid and list all the CPUs on which the process 
is allowed to run. It will then sleep for the specified number of <seconds> 
and display the CPU on which it is currently executing.

## Running on a Specific CPU

If you want to ensure that cpu_tester runs on a specific CPU, you can use 
it in conjunction with the `taskset` command. 

Here's an example:

```
$ taskset 0x1 ./cpu_tester <seconds>
```
This command will bind **cpu_tester** to the desired CPU. 
