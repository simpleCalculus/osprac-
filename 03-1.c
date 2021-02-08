#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(int argc, const char * argv[]) {
    printf("pid = %d\nppid = %d\n", (int)getpid(), (int)getppid());
    return 0;
}
