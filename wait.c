#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<unistd.h>
int main(){
        int pid,status,exitch;
        if((pid=fork())==-1){
                perror("error");
                exit(0);
        }
        if(pid==0){
                sleep(1);
                printf("Child process");
                exit(0);
        }
        else{
                printf("Parent process");
                if((exitch=wait(&status))==-1){
                        perror("during wait()");
                        exit(0);
                }
                printf("parent existing \n");
                exit(0);
        }
}
