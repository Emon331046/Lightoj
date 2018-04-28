#include<bits/stdc++.h>
using namespace std;
long long mod=100000007;
long long int a[100];
long long int tim[100];
long long int dp[1010][1010],n;
long long int rec(int sum,int pos)
{
    if(pos>=n)
    {
        if(sum==0)return 1;
        else return 0;
    }
    if(dp[sum][pos]!=-1)return dp[sum][pos];
    int ret=0;
    for(int i=0; i<=tim[pos]; i++)
    {
        if(sum-(i*a[pos])>=0)ret+=rec(sum-(i*a[pos]),pos+1);
        else break;
    }
    ret=ret%mod;
    return dp[sum][pos];
}
int main()
{
    int test,t=1;
    cin>>test;
    while(test--)
    {
        int sum,i;
        cin>>n>>sum;
        for(i=0; i<n; i++)cin>>a[i];
        for(i=0; i<n; i++)cin>>tim[i];
        long long ans;
        memset(dp,-1,sizeof(dp));
        ans=rec(sum,0);
        printf("Case %d: %lld\n",t++,ans);
    }
    return 0;
}

