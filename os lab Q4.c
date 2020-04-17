// Q.4 Write a program to display the last 10 characters of file on screen.
#include<stdio.h>
#include<stdlib.h>
int main() 
{
FILE *fptr;
char ch;
int num;
long length;
printf("It will print the last 10 characters of a file on screen\n");
fptr = fopen("file1.txt", "r");    
if (fptr == NULL) 
{
printf("cannot open this file\n");
printf("Please check whether file exists or not.\n");
exit(EXIT_FAILURE);
}
fseek(fptr, 0, SEEK_END);				   
length = ftell(fptr);      
fseek(fptr, (length - 10), SEEK_SET);  
do {
ch = fgetc(fptr);          
putchar(ch);
} while (ch != EOF);	   
fclose(fptr);              
return(0);
}





