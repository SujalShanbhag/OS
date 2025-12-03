#include <stdio.h> 
#include <sys/ipc.h> 
#include <sys/msg.h> 
struct msg { 
long type; 
char text[100]; 
}; 
void main() { 
key_t key = ftok("msgfile",65); // generate key 
int msgid = msgget(key,0666|IPC_CREAT); // create message queue 
struct msg message; 
message.type = 1; 
printf("Enter a message: "); 
scanf("%s",message.text); 
msgsnd(msgid,&message,sizeof(message.text),0); 
printf("Message sent.\n"); 
} 
