#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<err.h>

static void child(){
   printf("child my pid is %d.\n",getpid());
   exit(EXIT_SUCCESS);
}

static void parent(pid_t pid_c){
   printf("parent pid is %d and child pid is %d.\n",getpid(), pid_c);
   exit(EXIT_SUCCESS);
}

int main(void){
   pid_t ret;
   ret = fork();
   if(ret == 1)
     err(EXIT_FAILURE, "fork fail");
   if(ret == 0){
     child();
   }else{
     parent(ret);
   }
   err(EXIT_FAILURE, "shoudn't reach here");
}
