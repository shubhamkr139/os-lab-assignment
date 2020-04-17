// Q 2. WAP to implement race condition using semaphores.

#include<pthread.h>
#include<stdio.h>
#include<unistd.h>
#include<semaphore.h>
void *fun1(); 	//thread1 function declaration
void *fun2(); 	//thread2 function declaration
int shared=1; 	//shared variable declaration
sem_t s;     //semaphore variable
int main()
{
sem_init(&s,0,1);  	 // initailize semaphore variable
pthread_t thread1,thread2; 		
pthread_create(&thread1,NULL,fun1,NULL); 	
pthread_create(&thread2,NULL,fun2,NULL); 	
pthread_join(thread1,NULL); 			
pthread_join(thread2,NULL); 		
printf("FINAL VALUE OF SHARED VARIABLE IS %d \n",shared);
}

void *fun1()        
{
int x;	      
sem_wait(&s);     
x=shared;
x++; 		
sleep(1); 	
shared=x;
sem_post(&s);	 
}
void *fun2()
{
int y;		
sem_wait(&s);	
y=shared;	
y--; 		
sleep(3); 	
shared=y;
sem_post(&s);	
}


