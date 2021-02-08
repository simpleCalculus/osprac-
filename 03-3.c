#include <stdio.h>

int main(int argc, char *argv[], char *envp[]){
	printf("command line arguments:\n");
	for (int i = 0; i < argc; ++i) 
	{
		printf("argv[%d] = %s\n", i, argv[i]);	
	}	
	printf("\nenvironmental parameters:\n");
	int i = 0;
	while(envp[i] != NULL)
	{
		printf("envp[%d] = %s\n", i, envp[i]);
		i++;
	}
       	return 0;
}
