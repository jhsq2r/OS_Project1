#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char** argv){

        for(int x = 0; x < atoi(argv[1]); x++){
                printf("WORKER PID:%d PPID:%d Iteration:%d before sleeping\n", getpid(),getppid(),x+1);
                sleep(1);
                printf("WORKER PID:%d PPID:%d Iteration:%d after sleeping\n", getpid(),getppid(),x+1);
        }

        return 0;
}

