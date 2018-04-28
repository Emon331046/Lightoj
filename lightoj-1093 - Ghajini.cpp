#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<stdlib.h>
#include<stack>
#include<math.h>
#include<cstring>
#include<algorithm>
using namespace std;
#define pfc(x) printf("Case %d: ",x)
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
struct lol
{
    int mx;
    int mn;
} tree[400000];
int a[100000];
void input(int node,int bgn,int en)
{
    if(bgn==en)
    {
        tree[node].mx=a[bgn];
        tree[node].mn=a[bgn];
        return ;
    }

    int mid,left,right;

    mid=(bgn+en)/2;
    left=2*node;
    right=2*node+1;

    input(left,bgn,mid);//recursive
    input(right,mid+1,en);//recursive

    tree[node].mx=max(tree[left].mx,tree[right].mx);
    tree[node].mn=min(tree[left].mn,tree[right].mn);

    return ;
}
pii query(int node,int bgn,int en,int start,int finish)
{
    if(finish<bgn||start>en)
    {
        return pii(-1,999999999);
    }
    if(finish>=en&&start<=bgn)
    {
        return pii(tree[node].mx,tree[node].mn);
    }

    int mid,left,right;

    mid=(bgn+en)/2;
    left=2*node;
    right=2*node+1;

    pii q1,q2;

    q1=query(left  ,bgn   ,mid  ,start ,finish );
    q2=query(right ,mid+1 ,en   ,start ,finish );
    return pii(max(q1.first,q2.first),min(q1.second,q2.second));
}
int main()
{
    int tst,tt=1;
    sf1(tst);
    while(tst--)
    {
        int n,Q;
        sf2(n,Q);
        Q--;
        for(int i=0; i<n; i++)sf1(a[i]);

        input(1,0,n-1);

        int mx=0,crnt;

        for(int i=0; i+Q<n; i++)
        {
            pii tmp;
            tmp=query(1,0,n-1,i,i+Q);
            crnt=tmp.first-tmp.second;
            if(crnt>mx)mx=crnt;
        }
        pfc(tt++);
        pf1(mx);

    }
    return 0;
}
/*
3
6 2
6 0 8 8 8 4
8 3
19 8 4 13 12 1 0 13
2 2
1 1
*/
