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
int tree[120000],a[30005],sum[12000];
void input( int node , int start , int finish )
{
    if(start==finish)
    {
        tree[node]=a[start];
        sum[node]=a[start];
        return ;
    }
    int mid , left ,right ;
    mid=(start+finish)/2;
    left=2*node;
    right=left+1;
    input(left , start , mid );
    input( right , mid+1 ,finish );
    tree[node]=min(tree[left] , tree[right] );
    sum[node]=tree[node]*(finish-start+1);
    cout<<sum[node]<<' '<<node<<endl;
    sum[node]=max(max(sum[node],sum[left]),sum[right]);

}
int main()
{
    int tst,tt=1;
    sf1(tst);
    while(tst--)
    {
        int n;
        sf1(n);
        memset(sum,0,sizeof(sum));
        for(int i=1;i<=n;i++)sf1(a[i]);
        input(1,1,n);
        pfc(tt++);
        pf1(sum[1]);
    }
    return 0;
}
