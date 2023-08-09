#include<stdio.h> 
#include<sys/types.h> 
#include<unistd.h>
void main()
{
int a,b,c;
a=fork();
if(a<0)
printf("process creation is not poossible");
else
{
if(a==0)
{
c=getpid();
b=getpid();
printf("\n now in child process \n child id is %d \n parent id id is %d",b,c);
}
else
{
b=getppid();
printf("\n now in parent process \n parent id is %d",b);
}
}
}