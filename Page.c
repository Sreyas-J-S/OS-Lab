#include<stdio.h>
void fifo(int r[50],int frame[50],int n,int f)
{
int i,j,k,p,flag,count=0,pcount=0;
k=0;
for(i=0;i<n;i++)
{
flag = 0;
for(j=0;j<f;j++)
{
if(frame[j]==r[i])
{
flag = 1;
break;
}
else
{
flag = 0;
}
}
if(flag == 1)
{
pcount++;
}
else
{
count++;
frame[k] = r[i];
k++;
if(k==f)
{
k=0;
}
}
}
printf("No of page faults : %d\n",count);
printf("No of page hits : %d\n",pcount);
}
void optimal(int r[50],int frame[50],int n,int f)
{
int i,j,k,l,o,p,flag,count=0,far,han,flag1=0,pcount=0;
k=0;
for(i=0;i<n;i++)
{
flag = 0;
for(j=0;j<f;j++)
{
if(frame[j]==r[i])
{
flag = 1;
break;
}
else
{
flag = 0;
}
}
if(flag == 1)
{
pcount++;
}
else
{
int flag2 = 0,q;
for(p=0;p<f;p++)
{
if(frame[p]==-1)
{
flag2=1;
q=p;
break;
}
}
if(flag2 == 1)
{
frame[q]=r[i];
goto label;
}
far = i;
han = -1;
for(l=0;l<f;l++)
{
flag1 = 0;
for(o=i;o<n;o++)
{ 
if(frame[l]==r[o])
{
flag1 = 1;
if(o>far)
{
far = o;
han = l;
}
break;
}
}
if(flag1 == 0)
{
frame[l] = r[i];
goto label;
}
}
frame[han] = r[i];
label:
count++;
}
}
printf("No of page faults : %d\n",count);
printf("No of page hits : %d\n",pcount);
}
void lru(int r[50],int frame[50],int n,int f)
{
int i,j,k,l,o,p,flag,count=0,flag1=0,pcount=0;
int used[50],least,usage = 0;
for(i=0;i<n;i++)
{
used[i]=-1;
}
k=0;
for(i=0;i<n;i++)
{
flag = 0;
for(j=0;j<f;j++)
{
if(frame[j]==r[i])
{
flag = 1;
break;
}
else
{
flag = 0;
}
}
if(flag == 1)
{
pcount++;
for(p=0;p<n;p++)
{
if(r[i]==r[p])
{
used[p]=usage;
usage++;
break;
}
}
}
else
{
int flag2 = 0,q;
for(p=0;p<f;p++)
{
if(frame[p]==-1)
{
flag2=1;
q=p;
break;
}
}
if(flag2 == 1)
{
frame[q]=r[i];
goto label;
}
for(k=0;k<n;k++)
{
if(frame[0]==r[k])
{
least = used[k];
o = 0;
break;
}
}
for(l=0;l<f;l++)
{
for(k=0;k<n;k++)
{
if(frame[l]==r[k])
{
if(used[k]<least)
{
least = used[k];
o = l;
}
break;
}
}
}
frame[o] = r[i];
label:
count++;
for(p=0;p<n;p++)
{
if(r[i]==r[p])
{
used[p]=usage;
usage++;
break;
}
}
}
}
printf("No of page faults : %d\n",count);
printf("No of page hits : %d\n",pcount);
}
void mru(int r[50],int frame[50],int n,int f)
{
int i,j,k,l,o,p,flag,count=0,flag1=0,pcount=0;
int used[50],most,usage = 0;
for(i=0;i<n;i++)
{
used[i]=-1;
}
k=0;
for(i=0;i<n;i++)
{
flag = 0;
for(j=0;j<f;j++)
{
if(frame[j]==r[i])
{
flag = 1;
break;
}
else
{
flag = 0;
}
}
if(flag == 1)
{
pcount++;
for(p=0;p<n;p++)
{
if(r[i]==r[p])
{
used[p]=usage;
usage++;
break;
}
}
}
else
{
int flag2 = 0,q;
for(p=0;p<f;p++)
{
if(frame[p]==-1)
{
flag2=1;
q=p;
break;
}
}
if(flag2 == 1)
{
frame[q]=r[i];
goto label;
}
for(k=0;k<n;k++)
{
if(frame[0]==r[k])
{
most = used[k];
o = 0;
break;
}
}
for(l=0;l<f;l++)
{
for(k=0;k<n;k++)
{
if(frame[l]==r[k])
{
if(used[k]>most)
{
most = used[k];
o = l;
}
break;
}
}
}
frame[o] = r[i];
label:
count++;
for(p=0;p<n;p++)
{
if(r[i]==r[p])
{
used[p]=usage;
usage++;
break;
}
}
}
}
printf("No of page faults : %d\n",count);
printf("No of page hits : %d\n",pcount);
}
void main()
{
int r[50],frame[50];
int f,n,i,ch;
printf("Enter the no of pages in a frame\n");
scanf("%d",&f);
printf("Enter the length of reference string\n");
scanf("%d",&n);
printf("Enter the reference string\n");
for(i=0;i<n;i++)
{
scanf("%d",&r[i]);
}
do
{
for(i=0;i<f;i++)
{
frame[i]=-1;
}
printf("Enter the choice\n1.FIFO\n2.Optimal\n3.LRU\n4.MRU\n5.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
fifo(r,frame,n,f);
break;
case 2:
optimal(r,frame,n,f);
break;
case 3:
lru(r,frame,n,f);
break;
case 4:
mru(r,frame,n,f);
break;
}
}while(ch<5);
}

