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

#define sf1(x)            scanf("%d",&x)
#define sf2(x,y)         scanf("%lld%lld",&x,&y)
#define sf3(x,y,z)      scanf("%lld%lld%lld",&x,&y,&z)
#define sf4(x,y,z,m)   scanf("%lld%lld%lld%lld",&x,&y,&z,&m)
#define sfch(ch)        scanf(" %c ",&ch)
#define sfs(s)           scanf(" %s ",&s)
#define pfc(x)             printf("Case %lld: ",x)
#define pfcn(x)             printf("Case %lld:\n",x)
#define pf1(x)             printf("%lld\n",x)
#define pf2(x,y)          printf("%lld %lld\n",x,y)
#define pf3(x,y,z)       printf("%lld %lld %lld\n",x,y,z)
#define pf4(x,y,z,m)    printf("%lld %lld %lld %lld\n",x,y,z,m)
#define mod 1000000007
#define ll long long
#define llu unsigned long long
#define pii pair<int,int>
#define PI acos(-1.00)
#define pb push_back
#define ppb pop_back
long long lazy[ 4000000];
long long tree[1000000];
int n;
void update(int node,int bgn,int finish,int i, int j,int nwvalue)
{

        int mid,left,right;
        mid=(bgn+finish)/2;
        left=2*node;
        right=left+1;
    if(lazy[node]!=0)
    {
        tree[node]+=(finish-bgn+1)*lazy[node];
        if(bgn!=finish)
        {

            lazy[left]+=lazy[node];
            lazy[right]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(finish<i||bgn>j)return ;
    else if(bgn>=i&&finish<=j)
    {
        if(bgn!=finish)
        {
            lazy[left]+=nwvalue;
            lazy[right]+=nwvalue;
        }
        tree[node]+=(finish-bgn+1)*nwvalue;
    }
    else
    {
        update( left, bgn, mid, i, j, nwvalue);
        update( right, mid+1, finish,i, j, nwvalue );
        tree[node]=tree[left]+tree[right];
    }
}
long long query(int node,int bgn,int finish,int i, int j )
{
        int mid,left,right;
        mid=(bgn+finish)/2;
        left=2*node;
        right=left+1;
    if(lazy[node]!=0)
    {
        tree[node]+=((finish-bgn+1)*lazy[node]);
        if(bgn!=finish)
        {
            lazy[left]+=lazy[node];
            lazy[right]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(finish<i||bgn>j)return 0;
    else if(bgn>=i&&finish<=j)
    {
        return tree[node];
    }
    else
    {
        long long q1,q2;
        q1=query( left, bgn, mid, i, j );
        q2=query( right, mid+1, finish,i, j);
        return q1+q2;
    }
}

int main()
{
    int tst,tt=1;
    sf1(tst);
    while(tst--)
    {
        int  q, f,x, y, nwvalue ;
        pfcn(tt++);
        sf2( n, q );
        memset(lazy,0,sizeof(lazy));
        memset(tree,0,sizeof(tree));
        for(int k=0; k<q; k++)
        {
            sf1( f );
            if( f ==1)
            {
                sf2(x,y);
                pf1( query(1, 1, n, x+1, y+1) );
            }
            else
            {
                sf3( x, y, nwvalue );
                update( 1, 1, n, x+1,y+1, nwvalue );
            }
        }
    }
    return 0;
}

