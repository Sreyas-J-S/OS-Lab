#include <stdio.h>
#include<math.h>
#include<stdlib.h>
void fcfs(int n,int req[50],int in)
{
    int req1[50],in1,i;
    int hm=0,thm=0;
    for(i=0;i<n;i++)
    {
        req1[i]=req[i];
    }
    in1=in;
    for(i=0;i<n;i++)
    {
        hm=abs(req1[i]-in1);
        thm=thm+hm;
        printf("%d -> %d \n",in1,req1[i]);
        printf("Head movement = %d\n",hm);
        in1 = req1[i];
    }
    printf("Total Head movement = %d\n",thm);
}
void sstf(int n,int req[50],int in)
{
    int req1[50],in1,i,sh,key,k,dist[50],a[50];
    int hm=0,thm=0,j=0;
    for(i=0;i<n;i++)
    {
        req1[i]=req[i];
    }
    in1=in;
    for(k=0;k<n;k++)
    {
    for(i=0;i<n;i++)
    {
        dist[i]=abs(in1-req1[i]);
    }
    sh=dist[0];
    key=0;
    for(i=1;i<n;i++)
    {
        if(sh>dist[i])
        {
            sh=dist[i];
            key=i;
        }
    }
    a[j]=req1[key];
    j++;
    in1=req1[key];
    req1[key]=999;
    }
    in1=in;
    for(i=0;i<n;i++)
    {
        hm=0;
        if(a[i]>in1)
        {
            hm = a[i]-in1;
        }
        else
        {
            hm = in1-a[i];
        }
        thm=thm+hm;
        printf("%d -> %d \n",in1,a[i]);
        printf("Head movement = %d\n",hm);
        in1 = a[i];
    }
    printf("Total Head movement = %d\n",thm);

}
void look(int n,int req[50],int in, int max)
{
    int i=0,in1,q[50],q1[50],q2[50],j=0,k=0,n1=0,n2=0,temp,hm=0,thm=0;
    in1 = in;
    for(i=0;i<n;i++)
    {
        if(req[i]>in1)
        {
            q1[n1]=req[i];
            n1++;
        }
        else    
        {  
            q2[n2]=req[i];  
            n2++;
        }
    }
   
   
    for(i=0;i<n1-1;i++)
    {
        for(j=0;j<n1-i-1;j++)
        {
            if(q1[j]>q1[j+1])
            {
                temp=q1[j];
                q1[j]=q1[j+1];
                q1[j+1]=temp;
            }
        }
    }
   
    for(i=0;i<n2-1;i++)
    {
        for(j=0;j<n2-i-1;j++)
        {
            if(q2[j]<q2[j+1])
            {
                temp=q2[j];
                q2[j]=q2[j+1];
                q2[j+1]=temp;
            }
        }
    }
    j=0;
    for(i=1;j<n1;i++)
    {
        q[i]=q1[j];
        j++;
    }
    j=0;
    for(i=n1+1;j<n2;i++)
    {
        q[i]=q2[j];
        j++;
    }
    q[0]=in1;
    for(i=0;i<n;i++)
    {  
        hm = abs(q[i+1]-q[i]);
        thm = thm + hm;
        printf("%d -> %d \n", q[i], q[i+1]);
        printf("Head Movement : %d\n", hm);
    }
    printf("Total Head Movement : %d\n", thm);
}
void scan(int n,int req[50],int in, int max)
{
    int i=0,in1,q[50],q1[50],q2[50],j=0,k=0,n1=0,n2=0,temp,hm=0,thm=0;
    in1 = in;
    for(i=0;i<n;i++)
    {
        if(req[i]>in1)
        {
            q1[n1]=req[i];
            n1++;
        }
        else    
        {  
            q2[n2]=req[i];  
            n2++;
        }
    }
   
   
    for(i=0;i<n1-1;i++)
    {
        for(j=0;j<n1-i-1;j++)
        {
            if(q1[j]>q1[j+1])
            {
                temp=q1[j];
                q1[j]=q1[j+1];
                q1[j+1]=temp;
            }
        }
    }
   
    for(i=0;i<n2-1;i++)
    {
        for(j=0;j<n2-i-1;j++)
        {
            if(q2[j]<q2[j+1])
            {
                temp=q2[j];
                q2[j]=q2[j+1];
                q2[j+1]=temp;
            }
        }
    }
    j=0;
    for(i=1;j<n1;i++)
    {
        q[i]=q1[j];
        j++;
    }
    q[i]=max;
    j=0;
    for(i=n1+2;j<n2;i++)
    {
        q[i]=q2[j];
        j++;
    }
    q[i]=0;
    q[0]=in1;
    for(i=0;i<=n;i++)
    {  
        hm = abs(q[i+1]-q[i]);
        thm = thm + hm;
        printf("%d -> %d \n", q[i], q[i+1]);
        printf("Head Movement : %d\n", hm);
    }
    printf("Total Head Movement : %d\n", thm);
}
void clook(int n,int req[50],int in, int max)
{
    int i=0,in1,q[50],q1[50],q2[50],j=0,k=0,n1=0,n2=0,temp,hm=0,thm=0;
    in1 = in;
    for(i=0;i<n;i++)
    {
        if(req[i]>in1)
        {
            q1[n1]=req[i];
            n1++;
        }
        else    
        {  
            q2[n2]=req[i];  
            n2++;
        }
    }
   
   
    for(i=0;i<n1-1;i++)
    {
        for(j=0;j<n1-i-1;j++)
        {
            if(q1[j]>q1[j+1])
            {
                temp=q1[j];
                q1[j]=q1[j+1];
                q1[j+1]=temp;
            }
        }
    }
   
    for(i=0;i<n2-1;i++)
    {
        for(j=0;j<n2-i-1;j++)
        {
            if(q2[j]>q2[j+1])
            {
                temp=q2[j];
                q2[j]=q2[j+1];
                q2[j+1]=temp;
            }
        }
    }
    j=0;
    for(i=1;j<n1;i++)
    {
        q[i]=q1[j];
        j++;
    }
    j=0;
    for(i=n1+1;j<n2;i++)
    {
        q[i]=q2[j];
        j++;
    }
    q[0]=in1;
    for(i=0;i<n;i++)
    {  
        hm = abs(q[i+1]-q[i]);
        thm = thm + hm;
        printf("%d -> %d \n", q[i], q[i+1]);
        printf("Head Movement : %d\n", hm);
    }
    printf("Total Head Movement : %d\n", thm);
}
void cscan(int n,int req[50],int in, int max)
{
    int i=0,in1,q[50],q1[50],q2[50],j=0,k=0,n1=0,n2=0,temp,hm=0,thm=0;
    in1 = in;
    for(i=0;i<n;i++)
    {
        if(req[i]>in1)
        {
            q1[n1]=req[i];
            n1++;
        }
        else    
        {  
            q2[n2]=req[i];  
            n2++;
        }
    }
   
   
    for(i=0;i<n1-1;i++)
    {
        for(j=0;j<n1-i-1;j++)
        {
            if(q1[j]>q1[j+1])
            {
                temp=q1[j];
                q1[j]=q1[j+1];
                q1[j+1]=temp;
            }
        }
    }
   
    for(i=0;i<n2-1;i++)
    {
        for(j=0;j<n2-i-1;j++)
        {
            if(q2[j]>q2[j+1])
            {
                temp=q2[j];
                q2[j]=q2[j+1];
                q2[j+1]=temp;
            }
        }
    }
    j=0;
    for(i=1;j<n1;i++)
    {
        q[i]=q1[j];
        j++;
    }
    q[i]=max;
    q[i+1]=0;
    j=0;
    for(i=n1+3;j<n2;i++)
    {
        q[i]=q2[j];
        j++;
    }
    q[0]=in1;
    for(i=0;i<=n+1;i++)
    {  
        hm = abs(q[i+1]-q[i]);
        thm = thm + hm;
        printf("%d -> %d \n", q[i], q[i+1]);
        printf("Head Movement : %d\n", hm);
    }
    printf("Total Head Movement : %d\n", thm);
}
void main() {
    // Write C code here
    int i,n,req[50],ch,in,max;
    printf("Enter the maximum range of disk\n");
    scanf("%d",&max);
    printf("Enter the no of requests\n");
    scanf("%d",&n);
    printf("Enter the requests\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("Enter the initial head position\n");
    scanf("%d",&in);
    do
    {
        printf("Enter the choice\n1.FCFS\n2.SSTF\n3.LOOK\n4.SCAN\n5.CLOOK\n6.CSCAN\n7.Exit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            fcfs(n,req,in);
            break;
            case 2:
            sstf(n,req,in);
            break;
            case 3:
            look(n,req,in,max);
            break;
            case 4:
            scan(n,req,in,max);
            break;
            case 5:
            clook(n,req,in,max);
            break;
            case 6:
            cscan(n,req,in,max);
            break;
        }
    }while(ch<7);
}