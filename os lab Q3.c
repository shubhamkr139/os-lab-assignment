
//Q 3. write a program to send a message "end term practical" from parent   process to child process.
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int fd[2],n; 		
char buffer[100]; 	
pid_t p; 	
pipe(fd); 	
p=fork(); 	
if(p>0) 	
{
close(fd[0]);	
printf("Passing value to child\n");
write(fd[1],"End term practical\n",20); 	
sleep(1);
}
else 	
{
close(fd[1]);    
n=read(fd[0],buffer,100);     
write(1,buffer,n);       
}
}

