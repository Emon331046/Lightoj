#include<bits/stdc++.h>
using namespace std;
int tree[400000];
int a[100000];
void binarytree(int node,int beg,int endd)
{
    if(beg==endd)
    {
        tree[node]=a[beg];
        return ;
    }
    int left,right,mid;
    mid=(beg+endd)/2;
    left=2*node;
    right=2*node+1;
    binarytree(left,beg,mid);
    binarytree(right,mid+1,endd);
    tree[node]=min(tree[left],tree[right]);
}
int query(int node,int beg,int endd,int i,int j)
{
    if(i>endd||j<beg)return 1000005;
    if(beg>=i&&endd<=j)return tree[node];
    int left,right,mid;
    mid=(beg+endd)/2;
    left=2*node;
    right=2*node+1;
    int p1,p2;
    p1=query(left,beg,mid,i,j);
    p2=query(right,mid+1,endd,i,j);
    return min(p1,p2);
}
int main()
{
    int test,t=1;
    scanf("%d",&test);
    while(test--)
    {
        int n,q;
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++)cin>>a[i];
        printf("Case %d:\n",t++);
        binarytree(1,1,n);
        while(q--)
        {
            int b,e,sum;
            scanf("%d%d",&b,&e);
            sum=query(1,1,n,b,e);
            printf("%d\n",sum);
        }
    }
    return 0;
}

