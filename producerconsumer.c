#include <stdio.h> 
#include <stdlib.h> 
#define BUFFERSIZE 10 
int mutex = 1; 
int full = 0; 
int empty; 
int n, item, item1; 
int buffer[BUFFERSIZE]; 
int in = 0, out = 0; 
void wait(int *s) { 
while (*s <= 0); // Busy wait 
(*s)--; 
} 
void signal(int *s) { 
(*s)++; 
} 
void producer() { 
if ((in - out) >= n) { 
printf("Cannot add item,buffer full\n"); 
return; 
} 
wait(&empty); 
wait(&mutex); 
printf("\nEnter an item: "); 
scanf("%d",&item); 
buffer[in % BUFFERSIZE] = item; 
in++; 
signal(&mutex); 
signal(&full); 
} 
void consumer() { 
if (out >= in) { 
printf("No items to consume\n"); 
return; 
} 
wait(&full); 
wait(&mutex); 
item1 = buffer[out % BUFFERSIZE]; 
printf("\nConsumed item = %d", item1); 
out++; 
signal(&mutex); 
signal(&empty); 
} 
int main() { 
int choice; 
printf("Enter the number of items (n): "); 
scanf("%d", &n); 
if (n > BUFFERSIZE) { 
printf("Buffer size exceeded. Max allowed is %d\n", BUFFERSIZE); 
return 1; 
} 
empty = n; 
while (1) { 
printf("\n1. Produce\n2. Consume\n3. Exit\nEnter your choice: "); 
scanf("%d",&choice); 
switch (choice) { 
case 1: 
producer(); 
break; 
case 2: 
consumer(); 
break; 
case 3: 
exit(0); 
default: 
printf("Invalid choice\n"); 
} 
} 
return 0; 
} 
