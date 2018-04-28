/*
ID: hremon32
PROG:
LANG: C++11
*/
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>

using namespace std;
#define mod 1000000007
#define ll long long
#define llu unsigned long long
#define pii pair<int,int>
#define PI acos(-1.00)
#define pb push_back
#define ppb pop_back
#define pcs(t) cout<<"Case "<<t<<": "
int n;
int dp[20][1<<17];
int s[20][20];
int vis[20];
int check (int mask, int i)
{
    return   mask & (1<<i);
}
int update(int mask,int i)
{
    return mask | (1<<i);
}
int rec(int cnt,int mask)
{
    if(cnt==n)
    {
        return 0;
    }
    if(dp[cnt][mask] != -1)
    {
        return dp[cnt][mask];
    }

    int ret=0,ret1=0;

    for(int i=0; i<n; i++)
    {
        ret1=0;
        if(!check(mask,i))
        {
            ret1 = s[cnt][i] + rec( cnt+1,update(mask,i));
        }
        ret = max(ret,ret1);
    }
    return dp[cnt][mask]=ret;
}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin ("");
    ofstream fout ("");
    int tst,t=1;
    cin>>tst;
    while(tst--)
    {
        cin>>n;
        memset(dp,-1,sizeof(dp));
        for(int i=0; i<n; i++)for(int j=0; j<n; j++)cin>>s[i][j];
        pcs(t++);
        int mx= rec(0,0);
        cout<<mx<<endl;
    }
    return 0;
}


