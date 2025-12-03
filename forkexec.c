#include<stdio.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<sys/wait.h> 
int main() { 
pid_t pid; 
pid = fork(); 
if (pid < 0) { 
perror("fork failed"); 
return 1; 
} 
else if (pid == 0) { 
printf("Child process: executing 'ls -l'\n"); 
execl("/bin/date", "date", NULL); 
perror("execl failed"); 
} 
else { 
printf("Parent process: waiting for child to complete...\n"); 
wait(NULL); 
printf("Child completed. Parent exiting.\n"); 
} 
return 0; 
} 
