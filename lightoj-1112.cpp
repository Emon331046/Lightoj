#include<bits/stdc++.h>
using namespace std;
#define sf1(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d%d",&x,&y)
int tree[300005];
int a[100005],sum;
void input(int node,int beg,int en)
{
    if(beg==en)
    {
        tree[node]=a[beg];
        return ;
    }

    int mid,left,right;
    mid=(beg+en)/2;
    left=2*node;
    right=2*node+1;
    input(left,beg,mid);
    input(right,mid+1,en);
    tree[node]=tree[left]+tree[right];
}
int query(int node,int beg,int en,int i,int j)
{
    if(i<=beg&&j>=en)
    {
        return tree[node];
    }
    if(i>en||j<beg)return 0;

    int mid,left,right;
    mid=(beg+en)/2;
    left=2*node;
    right=2*node+1;
    int p1,p2;
    p1=query(left,beg,mid,i,j);
    p2=query(right,mid+1,en,i,j);
    return p1+p2;
}
void update(int node,int beg,int en,int i,int newvalue)
{
    if(en<i||i<beg)return;

    if(beg==i&&i==en)
    {
        tree[node]=tree[node]+newvalue;
        return ;
    }

    int mid,left,right;
    mid=(beg+en)/2;
    left=2*node;
    right=2*node+1;
    update(left,beg,mid,i,newvalue);
    update(right,mid+1,en,i,newvalue);
    tree[node]=tree[left]+tree[right];
}

void sumupdate(int node,int beg,int en,int i)
{
    if(en<i||i<beg)return;

    if(beg==i&&i==en)
    {
        sum=tree[node];
        tree[node]=0;
        return ;
    }

    int mid,left,right;
    mid=(beg+en)/2;
    left=2*node;
    right=2*node+1;
    sumupdate(left,beg,mid,i);
    sumupdate(right,mid+1,en,i);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    int test,t=1;
    sf1(test);
    while(test--)
    {
        int n,q,i,newvalue,c,j,ii;
        sf2(n,q);
        for(i=1; i<=n; i++)sf1(a[i]);
        input(1,1,n);
        printf("Case %d:\n",t++);
        while(q--)
        {
            sf1(c);
            if(c==1)
            {
                sf1(ii);
                sumupdate(1,1,n,ii+1);
                printf("%d\n",sum);
            }
            if(c==2)
            {
                sf2(ii,newvalue);
                update(1,1,n,ii+1,newvalue);
            }
            if(c==3)
            {
                sf2(ii,j);
                int ans1=query(1,1,n,ii+1,j+1);
                printf("%d\n",ans1);
            }
        }
    }
    return 0;
}
