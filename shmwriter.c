#include <stdio.h> 
#include <sys/ipc.h> // For IPC (Inter-Process Communication) key functions 
#include <sys/shm.h> // For shared memory functions 
int main() { 
key_t key = ftok("shmfile",65); 
int shmid = shmget(key, 1024, 0666 | IPC_CREAT); 
char *data = (char*) shmat(shmid, NULL, 0); 
printf("Enter data to write: "); 
scanf("%s", data); 
printf("Data written to shared memory.\n"); 
shmdt(data); 
return 0; 
} 
