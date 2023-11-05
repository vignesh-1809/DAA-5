#include <stdio.h>
void main()
{
    int n,m;
    int s1=0;
    int s2=0;
    scanf("%d",&m);
    int a[m];

    for(int i=0;i<m;i++)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&n);
    int b[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for(int i=0;i<m;i++)
    {

       s1=s1+a[i];


    }
    for(int i=0;i<n;i++)
    {
        s2+=b[i];
    }

    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if((s1-a[i]+b[j])==(s2-b[j]+a[i]))
               {

                   printf("%d %d",a[i],b[j]);
               }

        }
    }

}


