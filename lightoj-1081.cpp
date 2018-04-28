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
int sparse[501][501][12];
int arr[555][555];
int query(int x,int col,int ss)
{
    int mx=-1;
    int lg=log2(ss);
    for(int row=x; row<x+ss; row++)
    {
        mx=max(max(sparse[row][col][lg],sparse[row][col+ss-(1<<lg)][lg]),mx);
    }
    return mx;
}
void precal( int n )
{
    for(int row=1;row<=n;row++)for(int col=1;col<=n;col++)sparse[row][col][0]=arr[row][col];
    for(int row=1;row<=n;row++)
    {
        for(int lg=1;(1<<lg)<=n;lg++)
        {
            for(int col=1;col+(1<<lg)-1<=n;col++)
            {
                sparse[row][col][lg]=max(sparse[row][col][lg-1],sparse[row][col+(1<<(lg-1))][lg-1]);
            }
        }
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //ifstream fin ("");
    //ofstream fout ("");
    int tst,t=1;
    scanf("%d",&tst);
    while(tst--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++)for(int j=1; j<=n; j++)scanf("%d",&arr[i][j]);
        precal(n);
        printf("Case %d:\n",t++);
        while(q--)
        {
            int x,y,ss;
            scanf("%d%d%d",&x,&y,&ss);
            printf("%d\n",query(x,y,ss));
        }
    }
    return 0;
}



