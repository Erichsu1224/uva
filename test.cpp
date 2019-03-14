#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
using namespace std;

int main(void)
{
    pid_t pid;

    pid = fork();

	if(pid < 0){
        printf("1\n");
		fprintf(stderr, "Fork Failed");
		return 1;
	}

	else if(pid == 0){
        printf("2\n");
		execlp("/bin/ls", "ls", NULL);
	}

	else{
        printf("3\n");
		wait(NULL);
		printf("Child Complete");
	}

	return 0;

}
