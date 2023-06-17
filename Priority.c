#include<stdio.h>
#include<stdlib.h>
struct pri
{
int id;
int pri;
int btime;
int tat;
int wtime;
}P[10],temp;

void main()
{
int n,i,totalt=0,totalw=0,j;
float avgw,avgt;
printf("Enter the no of processes\n");
scanf("%d",&n);
for(i=0;i<n;i++)
{
P[i].id=i;
printf("Enter the burst time of Process %d\n",P[i].id);
scanf("%d",&P[i].btime);
printf("Enter the priority of Process %d\n",P[i].id);
scanf("%d",&P[i].pri);
}
for(i=1;i<n;i++)
{
for(j=0;j<n-i;j++)
{
if(P[j].pri>P[j+1].pri)
{
temp=P[j];
P[j]=P[j+1];
P[j+1]=temp;
}
}
}
P[0].wtime = 0;
P[0].tat=P[0].wtime+P[0].btime;
for(i=0;i<n;i++)
{
P[i].wtime = P[i-1].wtime + P[i-1].btime;
P[i].tat = P[i].wtime + P[i].btime;
totalt += P[i].tat;
totalw += P[i].wtime;
}
printf("Process id\tPriotrity\tBurst Time\tWaiting Time\tTurnaround Time\n");
for(i=0;i<n;i++)
{

printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n",P[i].id,P[i].pri,P[i].btime,P[i].wtime,P[i].tat);
}
printf("Total Waiting Time = %d\n",totalw);
printf("Total Turnaround Time = %d\n",totalt);
avgw = totalw * 1.0/n;
avgt = totalt * 1.0/n;
printf("Average Waiting Time = %f\n",avgw);
printf("Average Turnaround Time = %f\n",avgt);
}
