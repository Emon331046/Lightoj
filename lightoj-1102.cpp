#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
long long mod=1000000007;
long long a[2000005];
void fact()
{
    long long i,j;
    a[0]=1;
    a[1]=1;
    for(i=2;i<=2000000;i++)
    {
        a[i]=(a[i-1]*i)%mod;

    }
}
pii minverse(long long a,long long b)
{
    if(b==0)return pii(1,0);
    else
    {
        pii d=minverse(b,a%b);
        return pii(d.second,(d.first-((a/b)*d.second)));
    }
}
int main()
{
    long long i,j,test,t=1,n,r;
    fact();
    cin>>test;
    while(test--)
    {
        cin>>n>>r;
        long long s,d,f;
        n=n+r-1;
        s=a[n];
        d=(a[n-r+1]*a[r-1])%mod;
        pii p=minverse(d,mod);
        f=p.first;
        if(f<0)f+=mod;
        long long ans;
        ans=(f*s)%mod;
        printf("Case %lld: %lld\n",t++,ans);
    }
    return 0;
}
