/*
ID: hremon32
PROG:
LANG: C++11
*/
#include<bits/stdc++.h>
#include<iostream>
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
ll p[100];
ll func(ll x)
{
    if(x<0)return 0;
    if(x==0)return 1;
    ll tmp=0,cnt=0,ans=0;
    int flag=0;
    while(x!=0)
    {
        if(flag==0)ans=ans+(x/10);
        else ans=ans+((x/10)-1)*p[cnt];
        flag=1;
        tmp=(x%10)*p[cnt]+tmp;
        if(x%10==0)ans+=tmp+1;
        else ans+=p[cnt];
        x=x/10;
        cnt++;
    }
    //cout<<ans<<endl;
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    //ifstream fin ("");
    //ofstream fout ("");
    int tst,t=1;
    cin>>tst;
    p[0]=1;
    for(int i=1;i<11;i++)p[i]=p[i-1]*10;
    while(tst--)
    {
        ll n,m,ans;
        cin>>n>>m;
        ans=func(m)-func(n-1);
        cout<<"Case "<<t++<<": ";
        cout<<ans<<endl;
    }
    return 0;
}



