#include<stdio.h> 
#include<dirent.h>
struct dirent *dptr;
int main( char argc,char*argb[])
{
char dname[50];
DIR *dirp;
printf("Enter the name of the given directory you want to read \n");
scanf("%s",dname);
if((dirp=opendir(dname))==NULL)
{
printf("sorry opendir system call can't execute \n");
exit(1);
}
while(dptr=readdir(dirp))
{
printf("%s\n",dptr->d_name);
}
closedir(dirp);
}
