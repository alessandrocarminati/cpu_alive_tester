#define _GNU_SOURCE
#include <stdio.h>
#include <sched.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
	char *endptr;
	int value, cpu;
	cpu_set_t cpuset;

	printf("CPU alive tester\n");
	if (argc != 2) {
		printf("Usage: %s <integer>\n", argv[0]);
		return 1;
		}
	value = strtol(argv[1], &endptr, 10);
	if (*endptr != '\0') {
		printf("Invalid input: '%s' is not a valid integer.\n", argv[1]);
		return 1;
		}

	CPU_ZERO(&cpuset);
	if (sched_getaffinity(0, sizeof(cpu_set_t), &cpuset) == -1) {
		perror("sched_getaffinity");
		return 1;
		}

	printf("Process is allowed to run on the following CPUs:\n");
	for (cpu = 0; cpu < CPU_SETSIZE; cpu++) if (CPU_ISSET(cpu, &cpuset)) printf("CPU %d\n", cpu);

	printf("Sleeps for %d second(s)\n", value);
    	sleep(value);
	printf("Current CPU: %d\n", sched_getcpu());
	return 0;
}
