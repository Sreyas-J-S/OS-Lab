#include<stdio.h>



void firstfit(int p[20],int par[20],int n,int m)
{
int i,j,flag=0;
for(i=0;i<n;i++)
{
flag=0;
for(j=0;j<m;j++)
{
if(p[i]<=par[j])
{
printf("Process %d will fit in Partition %d\n",i+1,j+1);
par[j]=par[j]-p[i];
flag=1;
break;
}
}
if(flag==1)
{
continue;
}
if(flag==0)
{
printf("Process %d will have to wait\n",i+1);
}
}
}
void bestfit(int p[20],int par[20],int n,int m)
{
int i,j,flag=0,small,a[20];
for(i=0;i<n;i++)
{
a[i]=1;
}
for(i=0;i<m;i++)
{
flag=0;
for(j=0;j<m;j++)
{
if(p[i]<=par[j])
{
small=par[j];
break;
}
}
for(j=0;j<m;j++)
{
if(par[j]<small&&p[i]<=par[j])
{
small = par[j];
}
}

for(j=0;j<m;j++)
{
if(small==par[j])
{
printf("Process %d will fit in Partition %d\n",i+1,j+1);
par[j]=par[j]-p[i];
flag=1;
a[i]=0;

}
}
}
for(j=0;j<m;j++)
{
if(p[n-1]<=par[j])
{
small = par[j];
}
}
for(j=0;j<m;j++)
{
if(par[j]<small&&p[n-1]<=par[j])
{
small = par[j];
}
}
for(j=0;j<m;j++)
{
if(small==par[j])
{
printf("Process %d will fit in Partition %d\n",i+1,j+1);
par[j]=par[j]-p[n-1];
flag=1;
a[n-1]=0;

}
}
for(i=0;i<n;i++)
{
if(a[i]==1)
{
printf("Process %d will have to wait\n",i+1);
}
}
}
void worstfit(int p[20],int par[20],int n,int m)
{
int i,j,flag=0,big,a[20];
for(i=0;i<n;i++)
{
a[i]=1;
}
for(i=0;i<m;i++)
{
flag=0;
for(j=0;j<m;j++)
{
if(p[i]<=par[j])
{
big=par[j];
break;
}
}
for(j=0;j<m;j++)
{
if(par[j]>big&&p[i]<=par[j])
{
big = par[j];
}
}
for(j=0;j<m;j++)
{
if(big==par[j])
{
printf("Process %d will fit in Partition %d\n",i+1,j+1);
par[j]=par[j]-p[i];
flag=1;
a[i]=0;

}
}
}
for(j=0;j<m;j++)
{
if(p[n-1]<=par[j])
{
big = par[j];
}
}
for(j=0;j<m;j++)
{
if(par[j]>big&&p[n-1]<=par[j])
{
big = par[j];
}
}
for(j=0;j<m;j++)
{
if(big==par[j])
{
printf("Process %d will fit in Partition %d\n",i+1,j+1);
par[j]=par[j]-p[n-1];
flag=1;
a[n-1]=0;

}
}
for(i=0;i<n;i++)
{
if(a[i]==1)
{
printf("Process %d will have to wait\n",i+1);
}
}
}


void main()
{
int i,n,ch,p[20],par[20],m,p1[20],par1[20],p2[20],par2[20],p3[20],par3[20];
printf("Enter the no of processes\n");
scanf("%d",&n);
printf("Enter the no of partitions\n");
scanf("%d",&m);
printf("Enter the size of processes in KB\n");
for(i=0;i<n;i++)
{
printf("\nProcess %d : ",i+1);
scanf("%d",&p[i]);
}
printf("Enter the size of partitions in KB\n");
for(i=0;i<m;i++)
{
printf("\nPartition %d : ",i+1);
scanf("%d",&par[i]);
}

do
{
printf("Enter the choice\n1.First Fit\n2.Best Fit\n3.Worst Fit\n4.Exit\n");
for(i=0;i<n;i++)
{
p1[i]=p[i];
}
for(i=0;i<m;i++)
{
par1[i]=par[i];
}

scanf("%d",&ch);
switch(ch)
{
case 1:
firstfit(p1,par1,n,m);
break;

case 2:
bestfit(p1,par1,n,m);
break;

case 3:
worstfit(p1,par1,n,m);
break;

}
}while(ch<4);
}
