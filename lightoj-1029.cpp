#include<bits/stdc++.h>
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
#define pii pair<long long,long long>
#define pb push_back
int par[200],n,edge,tt=1;
struct lol
{
    int u;
    int v;
    int w;
} st[12100];
class comp
{
public:
    bool operator()(lol a,lol b)
    {
        return a.w>b.w;
    }
};
class comp2
{
public:
    bool operator()(lol a,lol b)
    {
        return a.w<b.w;
    }
};
void makeset()
{
    for(int i=0; i<=n; i++)par[i]=i;
}
int found(int m)
{
    if(par[m]==m)return m;
    else
    {
        par[m]=found(par[m]);
        return par[m];
    }
}
void scc1( )
{
    int sum=0,sum1=0,coun1=0;
    int coun=0;
    makeset();
    sort(st,st+edge,comp());
    for(int i=0; i<edge; i++)
    {
        int a,b,c;
        a=found(st[i].u);
        b=found(st[i].v);
        c=st[i].w;
        if(a!=b)
        {
            par[a]=b;
            sum+=c;
            coun++;
            if(coun==n)break;
        }
    }
    makeset();
    for(int i=edge-1; i>=0; i--)
    {
        int a,b,c;
        a=found(st[i].u);
        b=found(st[i].v);
        c=st[i].w;
        if(a!=b)
        {
            par[a]=b;
            sum1+=c;
            coun1++;
            if(coun1==n)break;
        }
    }
    pfc(tt++);
    if((sum+sum1)%2==0)pf1((sum+sum1)/2);
    else printf("%d/2\n",(sum+sum1));
}
int main()
{
    int tst;
    cin>>tst;
    while(tst--)
    {
        cin>>n;
        edge=0;
        int x,y,z;
        while(cin>>x>>y>>z)
        {
            if(x==0&&y==0&&z==0)break;
            st[edge].u=x;
            st[edge].v=y;
            st[edge].w=z;
            edge++;
        }
        scc1();
    }
    return 0;
}
