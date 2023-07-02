#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void main()
{
int fd[2],id;
char str[10],str1[10];
printf("Enter the string to be written to the pipe\n");
scanf("%s",str);
pipe(fd);
id = fork();
if(id<0)
{
printf("Fork failure\n");
}
else if(id>0)
{
close(fd[0]);
write(fd[1],str,5);
printf("Succesfully written to pipe\n");
close(fd[1]);
}
else
{
close(fd[1]);
read(fd[0],str,5);
printf("Sucessfully read from pipe : %s\n",str);
close(fd[0]);
}
}
