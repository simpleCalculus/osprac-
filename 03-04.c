#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[], char* envp[]) 
{
	int pid = (int)fork();			
	if (pid == -1) {
		printf("error\n");
	} else if (pid == 0) {
		printf("Child: PID = %d\n", (int)getpid());
		(void)execle("/bin/cat", "/bin/cat", "03-4.c", 0, envp);
		printf("ERROR\n");		
		exit(-1);
	} else {
		printf("Parent: ID: %d\n", (int)getpid());
	}
	return 0;
}
