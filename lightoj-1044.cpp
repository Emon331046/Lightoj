#include<bits/stdc++.h>
using namespace std;
char a[1009];
int dp[1009],len;
int is_palindrome(int s,int g)
{
    int i,j;
    for(i=s,j=g; i<j; i++,j--)if(a[i]!=a[j])return 0;
    return 1;
}
int rec(int start)
{
    if(start>=len)return 0;
    if(dp[start]!=-1)return dp[start];
    dp[start]=1000007;
    for(int i=start; i<len; i++)
    {
        if(is_palindrome(start,i))
        {
            dp[start]=min(dp[start],rec(i+1)+1);
        }
    }
    return dp[start];
}
int main()
{
    int test,t=1;
    cin>>test;
    while(test--)
    {
        cin>>a;
        memset(dp,-1,sizeof(dp));
        len=strlen(a);
        int ans=rec(0);
        printf("Case %d: %d\n",t++,ans);
    }
return 0;
}

