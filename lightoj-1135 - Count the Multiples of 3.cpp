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

#define sf1(x) scanf("%d",&x)
#define sfch(ch) scanf("%c",&ch)
#define sfs(s) scanf("%s",&s)
#define pfc(x) printf("Case %d: ",x)
#define pfcn(x) printf("Case %d:\n",x)
#define pf1(x) printf("%d\n",x)
#define pf2(x,y) printf("%d %d\n",x,y)
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z)
#define pf4(x,y,z,m) printf("%d %d %d %d\n",x,y,z,m)
#define mod 1000000007
#define ll long long
#define llu unsigned long long
#define pii pair<int,int>
#define PI acos(-1.00)
#define pb push_back
#define ppb pop_back
int tree[4][400005],lazy[400005],x,y;
void input(int node,int start,int finish)
{
    if(start==finish)tree[3][node]=1;
    else
    {
        int mid;
        mid=(start+finish)/2;
        input(2*node,start,mid);
        input(2*node+1,mid+1,finish);
        tree[3][node]=tree[3][2*node]+tree[3][2*node+1];
    }
}
void update( int node,int start,int finish )
{
    if(lazy[node]!=0)
    {
        int tmp1,tmp2,tmp3;
        tmp1=tree[1][node];
        tmp2=tree[2][node];
        tmp3=tree[3][node];
        if(lazy[node]%3==1)
        {
            tree[1][node]=tmp3;
            tree[2][node]=tmp1;
            tree[3][node]=tmp2;
        }
        else if(lazy[node]%3==2)
        {
            tree[1][node]=tmp2;
            tree[2][node]=tmp3;
            tree[3][node]=tmp1;
        }
        if(start!=finish)
        {
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(x>finish||y<start)return ;
    if(start>=x&&finish<=y)
    {
        int tmp1,tmp2,tmp3;
        tmp1=tree[1][node];
        tmp2=tree[2][node];
        tmp3=tree[3][node];
        tree[1][node]=tmp3;
        tree[2][node]=tmp1;
        tree[3][node]=tmp2;
        if(start!=finish)
        {
        lazy[2*node]++;
        lazy[2*node+1]++;
        }
        return ;
    }
    else
    {
        int mid;
        mid=(start+finish)/2;
        update(2*node,start,mid);
        update(2*node+1,mid+1,finish);
        tree[1][node]=tree[1][2*node]+tree[1][2*node+1];
        tree[2][node]=tree[2][2*node]+tree[2][2*node+1];
        tree[3][node]=tree[3][2*node]+tree[3][2*node+1];
    }
}
int query( int node,int start,int finish )
{
    if(lazy[node]!=0)
    {
        int tmp1,tmp2,tmp3;
        tmp1=tree[1][node];
        tmp2=tree[2][node];
        tmp3=tree[3][node];
        if(lazy[node]%3==1)
        {
            tree[1][node]=tmp3;
            tree[2][node]=tmp1;
            tree[3][node]=tmp2;
        }
        if(lazy[node]%3==2)
        {
            tree[1][node]=tmp2;
            tree[2][node]=tmp3;
            tree[3][node]=tmp1;
        }
        if(start!=finish)
        {
        lazy[2*node]+=lazy[node];
        lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(x>finish||y<start)return 0;
    if(start>=x&&finish<=y)
    {
        return tree[3][node];
    }
    else
    {
        int mid,q1,q2;
        mid=(start+finish)/2;
        q1=query(2*node,start,mid);
        q2=query(2*node+1,mid+1,finish);
        return q1+q2;
    }
}

int main()
{
    int tst,tt=1;
    sf1(tst);
    while(tst--)
    {
        int n,qq,flag;
        sf1(n);
        sf1(qq);
        pfcn(tt++);
        memset(lazy,0,sizeof(lazy));
        memset(tree,0,sizeof(tree));
        input(1,0,n-1);
        while(qq--)
        {
            sf1(flag);
            sf1(x);
            sf1(y);
            if(flag==0)update(1,0,n-1);
            else
            {
                int ans=query(1,0,n-1);
                pf1(ans);
            }
        }
    }
    return 0;
}

