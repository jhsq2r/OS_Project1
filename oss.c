#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/wait.h>

//Creator: Jarod Stagner
//Turn-in date: 09/13/2023

void help(){
        printf("Program usage\n-h = help\n-n [int] = Num Children to Launch\n-s [int] = Num of children allowed at once\n
                -t [int] = Num iterations for each child");
        printf("Default values are -n 5 -s 3 -t 3\nThis Program is designed to take in 3 integers for Num Processes,
                Num of processes allowed at once,\nand Num of iterations for each process");

}

int main(int argc, char** argv) {

        int proc = 5;
        int simul = 3;
        int iter = 3;//default parameters

        int option;
        while((option = getopt(argc, argv, "hn:s:t:")) != -1) {//Read command line arguments
                switch(option){
                        case 'h':
                                help();
                                return EXIT_FAILURE;
                                break;
                        case 'n':
                                proc = atoi(optarg);
                                break;
                        case 's':
                                simul = atoi(optarg);
                                break;
                        case 't':
                                iter = atoi(optarg);
                                break;
                        case '?':
                                help();
                                return EXIT_FAILURE;
                                break;
                }
        }
        //printf("Num Children: %d \nNum at once: %d \nNum iters: %d", proc,simul,iter);
        
        char convert[10];
        sprintf(convert, "%d", iter);//convert iter value to char
        
        for(int i = 0; i < proc; i++){
                if (i >= simul){
                        pid_t done_id = wait(NULL);//wait for a process to die before starting another
                        //printf("Process: %d is done\n", done_id);
                }

                pid_t child_pid = fork();
                if (child_pid == 0){
                        //printf("This is child %d\n", getpid());

                        char *args[] = {"./worker", convert, NULL};
                        execvp("./worker", args);//launch worker

                        printf("Something horrible happened...\n");
                        exit(1);
                }
        }
        for(int i = 0; i < simul; i++){
                wait(NULL);//wait for all children to die
        }
        printf("Done");
        return 0;

}
