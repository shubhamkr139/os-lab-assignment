#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define LEFT (num-1) %5
#define RIGHT (num+1)% 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0

int state[5];      
int philsph[5] ={0,1,2,3,4};    
sem_t mutex;        
sem_t S[5];



void test(int num)
{
if (state[num] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
{
state[num] =EATING;  
sleep(2);		
printf("Philosopher %d takes fork %d and %d\n", num + 1, LEFT + 1, num + 1); 
printf("Philosopher %d is Eating\n", num + 1); 

sem_post(&S[num]);     
}
}

void pickup(int num)      
{
sem_wait(&mutex);
state[num] = HUNGRY;
printf("Philosopher %d is Hungry\n", num + 1); 
test(num);  
sem_post(&mutex);
sem_wait(&S[num]);  
sleep(1);	
}

void putdown(int num) 	  
{
sem_wait(&mutex);
state[num] = THINKING;
printf("Philosopher %d putting fork %d and %d down\n", num + 1, LEFT + 1, num + 1); 
printf("Philosopher %d is thinking\n", num + 1); 
test(LEFT);  	
test(RIGHT);  
sem_post(&mutex);
}



void* philosopher (void* phnum) 
{
while(1)
{
int* i=phnum;
sleep(1);
pickup(*i);  
sleep(0);
putdown(*i); 
}
}



int main() 
{ 
int i; 
pthread_t thread_id[5]; 

sem_init(&mutex, 0, 1); 

for (i = 0; i < 5; i++) 

sem_init(&S[i], 0, 0); 

for (i = 0; i < 5; i++) { 

pthread_create(&thread_id[i], NULL, 
               philosopher, &philsph[i]); 

printf("Philosopher %d is thinking\n", i + 1); 
} 

for (i = 0; i < 5; i++) 
pthread_join(thread_id[i], NULL); 
} 

