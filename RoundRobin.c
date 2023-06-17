#include<stdio.h>
#include<stdlib.h>

void main()
{
int i,j,n,t=0,r,flag=0,tq,at[10],bt[10],rt[10],wt[10],tat[10];
int totalw=0,totalt=0,P[10];
float avgw,avgt;
printf("Enter the no of processes\n");
scanf("%d",&n);
r=n;
for(i=0;i<n;i++)
{
P[i]=i+1;
printf("Enter the burst time of process %d\n",i+1);
scanf("%d",&bt[i]);
printf("Enter the arrival time of process %d\n",i+1);
scanf("%d",&at[i]);
rt[i]=bt[i];
}
printf("Enter the time quantum\n");
scanf("%d",&tq);
printf("Process No\tBurstTime\tArrivalTime\tTurnaroundTime\tWaitingTime\n");
for(t=0,i=0;r!=0;)
{
if(rt[i]<=tq&&rt[i]>0)
{
t = t+rt[i];
rt[i] = 0;
  flag = 1;
}
else if(rt[i]>0)
{
rt[i]=rt[i]-tq;
t=t+tq;
}
if(rt[i]==0&&flag==1)
{
r--;
wt[i]=t-at[i]-bt[i];
tat[i]=t-at[i];
printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\n",P[i],bt[i],at[i],tat[i],wt[i]);
flag = 0;
}
if(i==n-1)
{
i=0;
}
else if(at[i+1]<=t)
{
i++;
}
else
{
i=0;
}
}
for(i=0;i<n;i++)
{
totalt += tat[i];
totalw += wt[i];
}
printf("Total Waiting Time = %d\n",totalw);
printf("Total Turnaround Time = %d\n",totalt);
avgw=totalw*1.0/n;
avgt=totalt*1.0/n;
printf("Average Waiting Time = %f\n",avgw);
printf("Average Turnaround Time = %f\n",avgt);
}
