#include<stdio.h>
struct fcfs
{
int at;
int bt;
int tat;
int wt;
}p[50],temp;

void main()
{
int i,n,j;
float totalw=0,avgw,totalt=0,avgt;
printf("Enter the no of processes\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
 printf("Enter arrrival time\n");
 scanf("%d",&p[i].at);
 printf("Enter burst time\n");
 scanf("%d",&p[i].bt);
}
for(i=1;i<n;i++)
{
for(j=0;j<n-i;j++)
{
if(p[i].at>p[j+1].at)
{
temp=p[j];
p[j]=p[j+1];
p[j+1]=temp;
}
}
}
p[0].wt=0;
p[0].tat=p[0].wt+p[0].bt;
for(i=0;i<n;i++)
{
p[i].wt=p[i-1].wt+p[i-1].bt;
p[i].tat=p[i].wt+p[i].bt;
totalt+=p[i].tat;
totalw+=p[i].wt;
}
printf("Process ID\tArrivaltime\tBursttime\tWaitingtime\tTurnaroundTime\n");
for(i=0;i<n;i++)
{
printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\n",i+1,p[i].at,p[i].bt,p[i].wt,p[i].tat);
}
printf("Total turnaround time = %f\nTotal waiting time = %f\n",totalt,totalw);
avgw = totalw/n;
avgt = totalt/n;
printf("Average turnaround time = %f\nAverage waiting time = %f\n",avgt,avgw);
}
