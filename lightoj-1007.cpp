#include<bits/stdc++.h>
using namespace std;
unsigned long long a[5000000+100];
int p[5000000+100];
void phi()
{
    for(int i=2; i<=5000000; i++)a[i]=i;
    for(int i=2; i<=5000000; i++)
    {
        if(p[i]==0)
        {
            for(int j=i+i; j<=5000000; j=j+i)
            {
                a[j]=((a[j]*i)-a[j])/i;
                p[j]=1;
            }
        }
    }
    a[1]=0;
    a[2]=1;
    for(int i=3; i<=5000000; i++)
    {
        if(p[i]==0)a[i]=a[i]-1;
        a[i]=a[i-1]+(a[i]*a[i]);
    }
}
int main()
{
    phi();
    int n,m,test,t=1;
    cin>>test;
    while(test--)
    {
        scanf("%d%d",&n,&m);
        unsigned long long ans;
        ans=a[m]-a[n-1];
        printf("Case %d: %llu\n",t++,ans);
    }
    return 0;
}
