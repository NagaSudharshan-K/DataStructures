#include<stdio.h>
void main()
{
int i,x,n;
printf("Enter the number of elements:");
scanf("%d",&n);
int arr[n];
printf("Enter the %d array elements:",n);
for(i=0;i<n;++i)
scanf("%d",&arr[i]);
printf("Enter element to search:");
scanf("%d",&x);
for(i=0;i<n;++i)
if(arr[i]==x)
break;
if(i<n)
printf("Element found at index %d",i);
else
printf("Element not found");
}