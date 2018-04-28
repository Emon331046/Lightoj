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
int dp[10010];
int grundy(ll x)
{
    if(dp[x]!=-1)return dp[x];
    set<int>s;
    for(int i=1;i<(x+1)/2;i++)
    {
        s.insert(grundy(i)^grundy(x-i));
    }
    int mn=0;
    while(s.find(mn)!=s.end())mn++;
    return dp[x]=mn;
}
int main()
{
    ios::sync_with_stdio(false);
    ifstream fin ("");
    ofstream fout ("");
    int tst,t=1;
    cin>>tst;
    memset(dp,-1,sizeof(dp));
    while(tst--)
    {
        int n,x;
        cin>>n;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            ans^=grundy(x);
        }
        cout<<"Case "<<t++;
        if(ans)cout<<": Alice"<<endl;
        else cout<<": Bob"<<endl;
    }
    return 0;
}



