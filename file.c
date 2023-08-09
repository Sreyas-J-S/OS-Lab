#include<stdio.h> 
#include<sys/types.h> 
#include<unistd.h> 
#include<fcntl.h> 
#include<stdlib.h>
void main()
{
char fname[50];
struct stat *s1;
s1=(struct stat *)malloc(sizeof(struct stat));
printf("enter the name of the file");
scanf("%s",fname);
stat(fname,s1);
printf("\n userid file creator is %d ",s1->st_uid);
printf("\n Block size of a given file %ld",s1->st_blksize);
printf("\n timw of last access %ld",s1->st_atime);
printf("\n the production mode of the file %d",s1->st_mode);
printf("\n size of the file %ld",s1->st_size);
printf("\n the link of file is %ld",s1->st_nlink);
}
