#include <sys/types.h>
#include <cstdio>
#include <iostream>
#include <unistd.h>
using namespace std;

int main(void)
{
    pid_t pid;

    pid = fork();

    cout << pid << endl;

    if(pid < 0)
    {
        fprintf(stderr, "Fork Failed");
        return 1;
    }

    else if(pid == 0)
    {
        execlp("bin/ls", "ls", NULL);
    }

    else
    {
        wait(NULL);
        printf("Child Complete\n");
    }

    return 0;
}