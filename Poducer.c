#include<stdio.h>
#include<stdlib.h>

int mutex=1;
int full=0;int empty =5,x=0;

void producer()
{
--mutex;
++full;
--empty;
x++;
printf("\nProducer produces item :%d",x); //incrementing  
++mutex;
}

void consumer()
{
--mutex;
--full;
++empty;
printf("\n Consumer consumes item : %d ",x); //decrementing
x--;
++mutex;
}


void main()
{
int ch,i;
do
{
printf("\n");
printf("\n Enter your choice \n1.Producer \n2.Consumer \n3.Exit\n");
scanf("%d",&ch);
switch(ch)
{
case 1:if((mutex==1)&&(empty!=0))
{
producer();
}
else
{
printf("\n Buffer is full");
}
break;

case 2:if((mutex==1)&&(full!=0))
{
consumer();
}
else
{
printf("\n Buffer is empty");
}
break;
case 3:exit(0);
break;
}
}while(ch<4);
}