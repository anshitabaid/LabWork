#include<sys/types.h> 
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h> 
int main()
{ 
    int status;
     pid_t pid;
     pid=fork();
     if (pid==-1){ 
        printf("\nError child not created");
     } 
     else if(pid==0){
      printf("\nIm the child%d",getpid()); 
      execlp("/bin/ps","ps",NULL);
      exit(0); 
    }
    else{ 
        
        printf("\nIm the parent%d",getpid());
        // execlp("/bin/ps","ps",NULL);
    }
  }