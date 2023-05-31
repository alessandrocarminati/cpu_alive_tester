#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char *endptr;
	int value, cpu;
	cpu_set_t cpuset;
	pid_t pid=getpid();

	printf("[%d] CPU alive tester\n", pid);
	if (argc != 2) {
		printf("[%d] Usage: %s <integer>\n", pid, argv[0]);
		return 1;
		}
	value = strtol(argv[1], &endptr, 10);
	if (*endptr != '\0') {
		printf("[%d] Invalid input: '%s' is not a valid integer.\n", pid, argv[1]);
		return 1;
		}

	CPU_ZERO(&cpuset);
	if (sched_getaffinity(0, sizeof(cpu_set_t), &cpuset) == -1) {
		printf("[%d] sched_getaffinity", pid);
		return 1;
		}

	printf("[%d] Process is allowed to run on the following CPUs:\n", pid);
	for (cpu = 0; cpu < CPU_SETSIZE; cpu++) if (CPU_ISSET(cpu, &cpuset)) printf("[%d] CPU %d\n", pid, cpu);

	printf("[%d] Sleeps for %d second(s)\n", pid, value);
	fflush(stdout);
    	sleep(value);
	printf("[%d] Current  starting CPU: %d\n", pid, sched_getcpu());
	for (int i=0; i<8;i++) {
		pid_t pidn = fork();
		cpu_set_t cpuset2;
		CPU_ZERO(&cpuset2);
		CPU_SET(i, &cpuset2);
		if (pidn == 0) {
			if (sched_setaffinity(0, sizeof(cpu_set_t), &cpuset2) == -1) {
				printf( "Failed to set CPU affinity\n");
				}
			printf("[%d] Current CPU: %d\n", getpid(), sched_getcpu());
			return 0;
			}
		}
	return 0;
}
