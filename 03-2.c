#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, const char * argv[]) {
	pid_t pid = fork();
	if ((int)pid == 0)
		printf("Child: PID = %d, PPID = %d\n", (int)getpid(), (int)getppid());	
	else if ((int)pid == -1)
		printf("error\n");
	else 
		printf("Parent: PID = %d, PPID = %d\n", (int)getpid(), (int)getppid());	
	return 0;
	
}
