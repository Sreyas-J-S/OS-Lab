#include<stdio.h>
struct sjf
{
int id;
int bt;
int tat;
int wt;
}p[50];

void main()
{
int i,n,j;
float totalw=0,avgw,totalt=0,avgt;
struct sjf temp;
printf("Enter the no of processes\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
 p[i].id = i+1;
 printf("Enter burst time\n");
 scanf("%d",&p[i].bt);
}
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(p[i].bt>p[j].bt)
{
temp=p[i];
p[i]=p[j];
p[j]=temp;
}
}
}
p[0].wt=0;
p[0].tat=p[0].wt+p[0].bt;
for(i=0;i<n;i++)
{
p[i].wt=p[i-1].wt+p[i-1].bt;
p[i].tat=p[i].wt+p[i].bt;
totalw+=p[i].wt;
totalt+=p[i].tat;
}
printf("Process ID\tBursttime\tWaitingtime\tTurnaroundTime\n");
for(i=0;i<n;i++)
{
printf("%d\t\t%d\t\t%d\t\t%d\t\n",i+1,p[i].bt,p[i].wt,p[i].tat);
}
printf("Total turnaround time = %f\nTotal waiting time = %f\n",totalt,totalw);
avgw = totalw/n;
avgt = totalt/n;
printf("Average turnaround time = %f\nAverage waiting time = %f\n",avgt,avgw);
}
