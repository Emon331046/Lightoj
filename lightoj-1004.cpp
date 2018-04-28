#include<bits/stdc++.h>
using namespace std;
int dp[505][505];
int  a[505][505],n;
int rec(int row,int i)
{
    if(row>=(2*n))
    {
        return 0;
    }
    if(dp[row][i]!=-1)
    {
        return dp[row][i];
    }
    if(row>=n)
    {
        if(i==1)
        {
            dp[row][i]=rec(row+1,i)+a[row][i];
            return dp[row][i];
        }
        if(i==(2*n)-row)
        {
            dp[row][i]=rec(row+1,i-1)+a[row][i];
            return dp[row][i];
        }
        dp[row][i]=max(rec(row+1,i),rec(row+1,i-1))+a[row][i];
        return dp[row][i];
    }
    if(row<n)
    {
        dp[row][i]=max(rec(row+1,i)+a[row][i],rec(row+1,i+1)+a[row][i]);
        return dp[row][i];
    }
}
int main()
{
    int test;
    int i,j,k,t=1;
    cin>>test;
    while(test--)
    {
    cin>>n;
    memset(dp,-1,sizeof(dp));
    memset(a,0,sizeof(a));
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)cin>>a[i][j];
    }
     for(i=n-1;i>0;i--)
    {
        for(j=1;j<=i;j++)cin>>a[2*n-i][j];
    }
    k=rec(1,1);
    printf("Case %d: %d\n",t++,dp[1][1]);
    }
    return 0;
}
