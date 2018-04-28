#include<bits/stdc++.h>
using namespace std;
int n,a[100][100];
int dp[100][100];
int rec(int row,int i)
{
    if(row>=n)
    {
        return 0;
    }
    if(dp[row][i]!=-1)
    {
        return dp[row][i];
    }
    if(i==0)
    {
        dp[row][i]=min(rec(row+1,1),rec(row+1,2))+a[row][i];
        return dp[row][i];
    }
    if(i==1)
    {
        dp[row][i]=min(rec(row+1,0),rec(row+1,2))+a[row][i];
        return dp[row][i];
    }
    if(i==2)
    {
        dp[row][i]=min(rec(row+1,0),rec(row+1,1))+a[row][i];
        return dp[row][i];
    }
}
int main()
{
    int test,t=1;
    cin>>test;
    while(test--)
    {
        memset(dp,-1,sizeof(dp));
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=0; i<n; i++)cin>>a[i][0]>>a[i][1]>>a[i][2];
        int ans1,ans;
        ans1=rec(0,0);
        ans=min(rec(0,1),rec(0,2));
        ans=min(ans,ans1);
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

