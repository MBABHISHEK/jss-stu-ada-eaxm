#include<stdio.h>
#include<stdlib.h>
#define x 10
#define y 100

int test=0;

float euclid(int m,int n)
{
int r;
float count=0;
while(n)
{
count++;
r=m%n;
m=n;
n=r;
}
printf("THE GCD IS %d\n",m);
return count;
}
float consec(int m, int n)
{
int min;
float count=0;
min=m;
if(n<min)
min=n;
while(1)
{
count++;
if(m%min==0)
{
count++;
if(n%min==0)
break;
min-=1;
}
else
min-=1;
}

printf("THE GCD IS %d\n",min);
return count;
}
float modified(int m,int n)
{
int temp;
float count=0;
while(n>0)
{
if(n>m)
{
temp=m;m=n;n=temp;
}
m=m-n;
count +=1 ;
}

printf("THE GCD IS %d\n",m);
return count; // m is the GCD
}


void main()
{
int ch;
while(1)
{
printf("GCD\n");
printf("1.Euclid\n2.modified Euclid\n3.consecutive integer method\n0to exit\n");
scanf("%d",&ch);
if(ch==0)
break;
printf("ENTER THE VALUES M AND N\n");
int m,n;
scanf("%d",&m);
scanf("%d",&n);
switch(ch)
{
case 1:euclid(m,n);break;
case 2:modified(m,n);break;
case 3:consec(m,n);break;
default:break;
}
}
}

