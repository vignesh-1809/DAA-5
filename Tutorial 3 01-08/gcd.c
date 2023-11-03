#include<stdio.h>
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
void main()
{
int p,n;
scanf("%d",&n);
int arr[n];
for(int i=0;i<n;i++)
{
    scanf("%d",&arr[i]);
}
p=arr[0];
for(int j=0;j<n-1;j++)
{

   p=gcd(p,arr[j+1]);
}
   printf("%d",p);

}
