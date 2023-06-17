#include<stdio.h>
void main()
{
int p,r,alloc[20][20],max[20][20],avail[20],remain[20][20],flag,mark[10],comp=1,k,f=0,l=0,safe[50];
printf("Enter the no of processes\n");
scanf("%d",&p);
printf("Enter the no of resources\n");
scanf("%d",&r);
int i,j,res;
for(i=0;i<p;i++)
{
printf("Enter the resources allocated to the process %d\n",i);
for(j=0;j<r;j++)
{
scanf("%d",&res);
alloc[i][j]=res;
}
printf("Enter the max need of the process %d\n",i);
for(j=0;j<r;j++)
{
scanf("%d",&res);
max[i][j]=res;
}
}
printf("Enter the available resources\n");
for(i=0;i<r;i++)
{
scanf("%d",&res);
avail[i]=res;
}
for(i=0;i<p;i++)
{
for(j=0;j<r;j++)
{
remain[i][j]=max[i][j]-alloc[i][j];
}
}
for(i=0;i<p;i++)
{
printf("\nRemaining need of process %d is \n",i);
for(j=0;j<r;j++)
{
printf("%d ",remain[i][j]);
}
printf("\n");
}
printf("Process\t\tAllocation\tMax Need\tAvailable\tRemaining Need\n");
for(i=0;i<p;i++)
{
printf("P%d\t\t",i);
for(j=0;j<r;j++)
{
printf("%d ",alloc[i][j]);
}
printf("\t\t");
for(j=0;j<r;j++)
{
printf("%d ",max[i][j]);
}
printf("\t\t");
if(i==0)
{
for(j=0;j<r;j++)
{
printf("%d ",avail[j]);
}
}

printf("\t\t");
for(j=0;j<r;j++)
{
printf("%d ",remain[i][j]);
}
printf("\n");
}
for(i=0;i<p;i++)
{
mark[i]=1;
}
do
{
f=0;
for(i=0;i<p;i++)
{
if(mark[i]==1)
{
flag=0;
for(j=0;j<r;j++)
{
if(remain[i][j]>avail[j])
{
flag=1;
}
}
if(flag==0)
{
printf("Process %d can be satisfied with available resources\n",i);
mark[i]=0;
for(k=0;k<r;k++)
{
avail[k]=avail[k]-remain[i][k]+max[i][k];
}
printf("Available resources after execution of Process %d\n",i);
for(k=0;k<r;k++)
{
printf("%d ",avail[k]);
}
printf("\n");
safe[l]=i;
l++;
}
}
}
for(k=0;k<p;k++)
{
if(mark[k]==1)
{
f=1;
}
}
if(f==0)
{
comp=0;
}
}while(comp==1);
printf("Safe Sequence is ");
for(int i=0;i<l;i++)
{
printf("P%d ",safe[i]);
}
}