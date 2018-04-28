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
long long lazy[400050],a[100050],tree[400050];
int x,y,val;
void update(int node,int start,int finish )
{
    if(lazy[node]!=-1)
    {
        tree[node]=(finish-start+1)*lazy[node];
        if(start!=finish)
        {
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=-1;
    }
    if(y<start||x>finish)return ;
    else if(start>=x&&finish<=y)
    {
        tree[node]=(finish+1-start)*val;
        if(start!=finish)
        {
            lazy[2*node]=val;
            lazy[2*node+1]=val;
        }
    }
    else
    {
        int mid;
        mid=(start+finish)/2;
        update( 2*node, start, mid );
        update( 2*node+1, mid+1, finish );
        tree[node]=tree[2*node]+tree[2*node+1];
    }
}
long long query(int node,int start,int finish )
{
    if(lazy[node]!=-1)
    {
        tree[node]=(finish-start+1)*lazy[node];
        if(start!=finish)
        {
            lazy[2*node]=lazy[node];
            lazy[2*node+1]=lazy[node];
        }
        lazy[node]=-1;
    }
    if(y<start||x>finish)return 0;
    else if(start>=x&&finish<=y)
    {
        return tree[node];
    }
    else
    {
        int mid;
        mid=(start+finish)/2;
        long long q1=query( 2*node, start,mid );
        long long q2=query( 2*node+1,mid+1,finish);
        return q1+q2;
    }

}
long long gcd(long long a,long long b)
{
    if(b==0)return a;
    return gcd(b,a%b);
}
int main()
{
    int tst,tt=1;
    sf1(tst);
    while(tst--)
    {
        int n,q,qq;
        sf1(n);
        sf1(q);
        pfcn(tt++);
        memset(lazy,-1,sizeof(lazy));
        memset(tree,0,sizeof(tree));
        for(int ii=0; ii<q; ii++)
        {
            sf1(qq);
            if(qq==1)
            {
                scanf("%d%d%d",&x,&y,&val);
                update(1,0,n-1);
            }
            else
            {
                scanf("%d%d",&x,&y);
                long long ans=query(1,0,n-1);
                long long divide=y-x+1;
                if(ans%divide==0)pf1(ans/divide);
                else
                {
                    long long num;
                    num=gcd(ans,divide);
                    printf("%lld/%lld\n",ans/num,divide/num);
                }
            }
        }
    }
    return 0;
}

