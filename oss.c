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
        //Make child here
}
