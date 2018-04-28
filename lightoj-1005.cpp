#include<bits/stdc++.h>
using namespace std;
long long perm(int n,int r)
{
    long long ans=1;
    for(int i=n-r+1; i<=n; i++)
    {
        ans=ans*i;
    }
    return ans;
}
long long comb(int n,int r)
{
    int i,j,k;
    k=n-r;
    if(k>r)
    {
        j=k;
        k=r;

    }
    else
    {
        j=r;
    }
    long long ans=1;
    int d=1;
    for(i=j+1; i<=n; i++)
    {
        ans=ans*i;
        if(d<=k&&ans%d==0)
        {
            ans/=d;
            d++;
        }
    }
    return ans;
}
int main()
{
    int test,t=1,i,j,n,m,r;
    cin>>test;
    while(test--)
    {
        unsigned long long ans,ans1;
        cin>>n>>m;
        if(n<m)
        {
            printf("Case %d: 0\n",t++);
        }
        else
        {
            ans=comb(n,m);
            ans1=perm(n,m);
            ans=ans*ans1;
            printf("Case %d: %llu\n",t++,ans);
        }

    }
    return 0;
}
