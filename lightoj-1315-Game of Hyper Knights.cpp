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
int fx[ ] = { -3,-2,-2,-1,-1,1 };
int fy[ ] = { -1,-1,1,-3,-2,-2 };
int dp[505][505];
int grundy(int x,int y)
{
    if(dp[x][y]!=-1)return dp[x][y];
    int tx,ty;
    set<int>s;
    for(int i=0;i<6;i++)
    {
        tx=x+fx[i];
        ty=y+fy[i];
        if(tx>=0&&ty>=0)
        {
            s.insert(grundy(tx,ty));
        }
    }
    int mn=0;
    while(s.find(mn)!=s.end())mn++;
    return dp[x][y]=mn;
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
        int n;
        cin>>n;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            ans^=grundy(x,y);
        }
        cout<<"Case "<<t++;
        if(ans)cout<<": Alice"<<endl;
        else cout<<": Bob"<<endl;
    }
    return 0;
}

