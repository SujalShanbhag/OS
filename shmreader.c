#include <stdio.h> 
#include <sys/ipc.h> // For IPC (Inter-Process Communication) key functions 
#include <sys/shm.h> // For shared memory functions 
int main() { 
key_t key = ftok("shmfile", 65); 
int shmid = shmget(key, 1024, 0666); 
char *data = (char*) shmat(shmid, NULL, 0); 
printf("Data read from shared memory: %s\n", data); 
shmdt(data); 
shmctl(shmid, IPC_RMID, NULL); 
return 0; 
} 
