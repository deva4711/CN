#include<stdio.h>
#include<string.h>
main()
{
char a[50],b[50],c[50];
inti,j,k,m=0,count,l1,l2;
printf(“\nEnter the data to send:”);
fflush(stdin);
gets(a);
printf(“\nEnter the delimeter:”);
fflush(stdin);
gets(b); l1=strlen(a); l2=strlen(b);
c[0]=’S’;
for(i=0;i<l2;i++)
c[i+1]=b[i]; for(j=0;j<l1;j++)
{
count=0; for(k=0,m=j;k<l2;k++,m++)
{
if(a[m]!=b[k])
count=1;
}
if(count==0)
{
for(k=l1+l2-1;k>m;k–)
a[k]=a[k-l2]; for(k=0;k<l2;k++)
a[m++]=b[k];
j=j+l2; l1=l1+l2;
}
}
for(k=0;k<l1;k++) c[++i]=a[k];
for(k=0;k<l2;k++) c[++i]=b[k];
c[++i]=’E’;
printf(“\nData after stuffing:”);
for(k=0;k<=i;k++)
printf(“%c”,c[k]);
for(j=0;j<l1-l2;j++)
{
count=0; m=j;
for(k=0;k<l2;k++)
{
if(a[m++]!=b[k]) count=1;
}
if(count==0)
{
for(k=m;k<l1-l2;k++) a[k]=a[k+l2];
l1=l1-l2;
}
}
printf(“\nData after destuffing:”);
for(i=0;i<l1;i++)
printf(“%c”,a[i]);
}
