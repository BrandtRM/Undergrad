#include <stdio.h>
#include <assert.h>
// TO DO
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(int argc, char** argv)
{
    assert(argc >= 2); 
    char* cmd = "./greeter";
    char* const parmList[] = {cmd, argv[1], NULL};

    // TO DO
    pid_t child = fork();
    if(child == 0){
        execvp(cmd, parmList);
        printf("Hello World!\n");
        return -1;
    }
    int status;
    waitpid(child, &status, 0);
    printf("Child process (pid: %d) exited with status %d.\n", child, 3);
    
    printf("Parent Process (pid: %d) exiting now.\n", getpid());
    
    return 0;
}