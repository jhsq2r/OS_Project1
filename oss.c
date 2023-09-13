#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <getopt.h>
#include <sys/wait.h>

void help(){
        printf("Is this helping????");
}

int main(int argc, char** argv) {

        int proc = 5;
        int simul = 3;
        int iter = 3;//default parameters

        int option;
        while((option = getopt(argc, argv, "hn:s:t:")) != -1) {
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
                                break;
                }
        }
        printf("Num Children: %d \nNum at once: %d \nNum iters: %d", proc,simul,iter);
        
        char convert[10];
        sprintf(convert, "%d", iter);
        //Make child here
        for(int i = 0; i < proc; i++){
                if (i >= simul){
                        pid_t done_id = wait(NULL);
                        printf("Process: %d is done\n", done_id);
                }

        pid_t child_pid = fork();
        if (child_pid == 0){
                printf("This is child %d\n", getpid());

                char *args[] = {"./worker", convert, NULL};
                execvp("./worker", args);

                printf("Something horrible happened...\n");
                exit(1);
        }
        }
        for(int i = 0; i < simul; i++){
                wait(NULL);
        }
        printf("Done");
        return 0;

}
