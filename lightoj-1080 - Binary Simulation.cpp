#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<stack>
#include<math.h>
#include<cstring>
#include<algorithm>
using namespace std;
#define pfc(x) printf("Case %d:\n",x)
#define sf1(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d%d",&x,&y)
#define sf3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sf4(x,y,z,m) scanf("%d%d%d%d",&x,&y,&z,&m)
#define pf1(x) printf("%d\n",x)
#define pf2(x,y) printf("%d %d\n",x,y)
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z)
#define pf4(x,y,z,m) printf("%d %d %d %d\n",x,y,z,m)
#define pii pair<int,int>
#define pb push_back
char a[100010];
int tree[400000],lazy[400000],ans;
void input(int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=a[b]-'0';
        return ;
    }
    int mid,left,right;
    mid=(b+e)/2;
    left=2*node;
    right=2*node+1;
    input(left,b,mid);
    input(right,mid+1,e);
    return;
}
void update(int node,int b,int e,int i,int j)
{
    if(b>j||e<i)return ;
    if(b>=i&&e<=j)
    {
        lazy[node]++;
        return ;
    }
    int mid,left,right;
    mid=(b+e)/2;
    left=2*node;
    right=2*node+1;
    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    return ;
}
void query(int node,int b,int e,int i,int crnt)
{
    if(i==b&&i==e)
    {
        crnt+=lazy[node];
        if(crnt%2==1)
        {
            ans=(tree[node]+1)%2;
            return ;
        }
        else
        {
            ans=tree[node];
            return ;
        }
    }
    if(i<b||i>e)return ;
    int mid,left,right;
    mid=(b+e)/2;
    left=2*node;
    right=2*node+1;
    query(left,b,mid,i,crnt+lazy[node]);
    query(right,mid+1,e,i,crnt+lazy[node]);
    return;
}
int main()
{
    int tst,tt=1;
    sf1(tst);
    while(tst--)
    {
        scanf("%*c%s",&a);
        memset(lazy,0,sizeof(lazy));
        int l;
        l=strlen(a);
        input(1,0,l-1);
        int n;
        pfc(tt++);
        sf1(n);
        while(n--)
        {
            char ch;
            scanf("%*c%c",&ch);
            if(ch=='I')
            {
                int i,j;
                sf2(i,j);
                update(1,0,l-1,i-1,j-1);
            }
            else
            {
                int i;
                sf1(i);
                query(1,0,l-1,i-1,0);
                pf1(ans);
            }
        }
    }
    return 0;
}
