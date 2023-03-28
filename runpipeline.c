#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#include <errno.h>
#include <assert.h>

#define ERROR_MSG(x)  fprintf(stderr, "%s\n", (x))

#define BUF_SIZE    1024
#define MAX_TASKS   10

typedef struct program_tag {
    char**   args;      // array of pointers to arguments
    int      num_args;  // number of arguments
    int	     pid;	// process ID of this program
    int      fd_in;     // FD for stdin
    int      fd_out;    // FD for stdout
} Program;


/* start a program
 * The informaton about one or more programs is passed in.
 * parameters:
 *      progs:  array of pointers to Program.
 *      total:  the number of valid programs in progs.
 *      cur:  the index of the Program (in the progs array) that needs to be startex
 *
 *  You need fork and then turn child into the program.
 *  Create pipes or use the pipes already created.
 *  Close pipes that are not used.
 */
void start_program(Program *progs, int total, int cur)
{
  /* Start by forking, so that we have a parent process, and a child process */
    int pd[2];
    if(pipe(pd) == -1)
    {
        perror("Error.");
    }

    pid_t pid = fork(); 
    if(pid == 0)
    {
        dup2(pd[1], 1);
        close(pd[1]);
        close(pd[0]);
        // Program
        
    }
    int status;
    waitpid(pid, &status, 0);
    close(pd[1]);



    
    int pd1[2];
    if(pipe(pd1) == -1)
    {
        perror("Error.");
    }
    
    pid_t pid1 = fork();
    if(pid1 == 0)
    {
        dup2(pd[0], 0);
        close(pd[0]);
        dup2(pd1[1], 1);
        close(pd1[1]);
        // Program
        
    }
    waitpid(pid1, &status, 0);
    close(pd[0]);
    close(pd1[1]);
    
    
    
    
    int pd2[2];
    if(pipe(pd2) == -1)
    {
        perror("Error.");
    }
    
    pid_t pid2 = fork();
    if(pid2 == 0)
    {
        dup2(pd1[0], 0);
        close(pd1[0]);
        dup2(pd2[1], 1);
        close(pd2[1]);
        // Program
        
    }
    waitpid(pid2, &status, 0);
    close(pd1[0]);
    close(pd2[1]);
    
    
    
    
    int pd3[2];
    if(pipe(pd3) == -1)
    {
        perror("Error.");
    }
    
    pid_t pid3 = fork();
    if(pid3 == 0)
    {
        dup2(pd2[0], 0);
        close(pd2[0]);
        dup2(pd3[1], 1);
        close(pd3[1]);
        // Program
        
    }
    waitpid(pid3, &status, 0);
    close(pd2[0]);
    close(pd3[1]);
    
    
    
    
    int pd4[2];
    if(pipe(pd4) == -1)
    {
        perror("Error.");
    }
    
    pid_t pid4 = fork();
    if(pid4 == 0)
    {
        dup2(pd3[0], 0);
        close(pd3[0]);
        dup2(pd4[1], 1);
        close(pd4[1]);
        // Program
        
    }
    waitpid(pid4, &status, 0);
    close(pd3[0]);
    close(pd4[1]);
    
    
    
    
    
    int pd5[2];
    if(pipe(pd5) == -1)
    {
        perror("Error.");
    }
    
    pid_t pid5 = fork();
    if(pid5 == 0)
    {
        dup2(pd4[0], 0);
        close(pd4[0]);
        dup2(pd5[1], 1);
        close(pd5[1]);
        // Program
        
    }
    waitpid(pid5, &status, 0);
    close(pd4[0]);
    close(pd5[1]);
    
    
    
    
    
    
    pid_t pid6 = fork();
    if(pid6 == 0)
    {
        dup2(pd5[0], 0);
        close(pd5[0]);
        // Program

    }
    waitpid(pid6, &status, 0);
    close(pd5[0]);

  /* Here's an (imperfect) analogy to help you with the pipes: Imagine the programs as lightbulbs hooked up in series (like the really crappy christmas tree lights where if one goes out, they all go out). If you've implemented prepare_pipes, then you've laid out the wires to connect the lightbulbs (but haven't hooked them up yet!).

     Let's say cur = 1, just as an example (and there are 4 programs). Currently, our pipes look like this:

           +-------------+                     +-------------+                 +-------------+                  +-------------+
User input |             |                     |             |                 |             |                  |             |
           | Process 0   |                     | Process 1   |                 | Process 2   |                  | Process 3   | Process Output
 +-------> |             +------------+        |             |                 |             |                  |             | +---------->
           |             |            |        |             |                 |             |                  |             |
           |             |            |        |             |                 |             |                  |             |
           +-------------+            |        +-------------+                 +-------------+                  +-------------+
                                      |
                                     <+--->
                                                               +----------->                     +--------->

   That is, we've hooked the output of lightbulb 0 to the wire; now, we need this wire to connect to the input of lightbulb 1, and for lightbulb 1, we need to hook the output to the next wire. Note that we also have file descriptors (think of them as pointers) to the pipe between process 2 and 3. Before we execute process 1 ("turn the lightbulb on"), we need to close these pointers. Note that this does NOT close the parent process' access to the pipe. So, our pipes/wires should look like this before we execute the program:

           +-------------+                     +-------------+                 +-------------+                  +-------------+
User input |             |                     |             |                 |             |                  |             |
           | Process 0   |                     | Process 1   |                 | Process 2   |                  | Process 3   | Process Output
 +-------> |             +------------------>  |             +----------+      |             |                  |             | +---------->
           |             |                     |             |          |      |             |                  |             |
           |             |                     |             |          |      |             |                  |             |
           +-------------+                     +-------------+          v      +-------------+                  +-------------+


With respect to the parent process, does it need access to the file descriptor's of prog[cur]'s pipe? 

  */                                                                                                                                                                                                      
  
  
}

/* Wait on a program.
 */
int wait_on_program(Program *prog)
{
    // TODO
    wait(NULL);
    return 0;
}


/* create pipes to be used for communication
 * between processes.
 * you can create all pipes here.
 * Or you can create pipes when they are needed in start_program().
 * If you decided to create pipes in start_program(),
 * Leave this function empty.
 */
void prepare_pipes(Program *prog, int num_programs)
{
    // TODO
}

/* clean up for all programs.
 */
void cleanup_programs(Program *prog, int num_programs)
{
    // TODO
    for(int i = 0; i < num_programs; i++)
    {

    }
}


/*********************************************************/
/* Do not change code below                              */
/*********************************************************/
void init_program(Program *prog, int na)
{
    // allocate memory for array of arguments
    prog->args = malloc(na * sizeof(char *));
    assert(prog->args != NULL);
    prog->num_args = 0;

    prog->pid = prog->fd_in = prog->fd_out =  -1;
}

int main(int argc, char **argv)
{
    Program progs[MAX_TASKS];
    int     num_programs;

    if (argc <= 1) {
        ERROR_MSG("Specify at least one program to run. Multiple programs are separated by --");
        exit(-1);
    }

    fprintf(stderr, "Parent started. pid=%d\n", getpid());

    // Prepare programs and their arguments
    num_programs = 0;
    int     cur_arg = 1;
    while (cur_arg < argc) {

        init_program(&progs[num_programs], argc);

        int     ia;
        for (ia = 0; cur_arg < argc; cur_arg ++) {
            if (!strcmp(argv[cur_arg], "--")) {
                if (num_programs == MAX_TASKS -  1) {
                    ERROR_MSG("Too many programs.");
                    exit(-1);
                }
                if (cur_arg + 1 == argc) {
                    ERROR_MSG("The last program is empty.");
                    exit(-1);
                }
                cur_arg ++;
                break;
            }
            progs[num_programs].args[ia++] = argv[cur_arg];
        }
        if (ia == 0) {
            ERROR_MSG("Empty program.");
            exit(-1);
        }
        progs[num_programs].args[ia] = NULL;
        progs[num_programs].num_args = ia;
        num_programs ++;
    }

    // Prepare pipes
    prepare_pipes(progs, num_programs);

    // spawn children
    for (int i = 0; i < num_programs; i ++) {
        start_program(progs, num_programs, i);
    }

    // wait for children
    for (int i = 0; i < num_programs; i ++) {
        fprintf(stderr, "Waiting for child %2d (%5d)...\n", i, progs[i].pid);
        wait_on_program(&progs[i]);
    }

    // cleanup
    cleanup_programs(progs, num_programs);

    fprintf(stderr, "Everything is good.\n");
    return 0;
}
