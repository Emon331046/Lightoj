#include<bits/stdc++.h>
using namespace std;
#define pfc(x) printf("Case %d: ",x)
#define sf1(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d%d",&x,&y)
#define sf3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sf4(x,y,z,m) scanf("%d%d%d%d",&x,&y,&z,&m)
#define pf1(x) printf("%d\n",x)
#define pf2(x,y) printf("%lld %lld\n",x,y)
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z)
#define pf4(x,y,z,m) printf("%d %d %d %d\n",x,y,z,m)
#define pii pair<int ,int >
long long n,ans,edge,coun,sum,cst;
int par[10005];
struct lol
{
    int u;
    int v;
    int w;
} s[100005];
class comp
{
public:
    bool operator()(lol a,lol b)
    {
        return a.w<b.w;
    }
};
int fnd(int m)
{
    if(par[m]==m)return m;
    else
    {
        par[m]=fnd(par[m]);
        return par[m];
    }
}
int scc()
{
    for(int i=1;i<=n;i++)par[i]=i;
    coun=0;
    sum=0;
    for(int i=0;i<edge;i++)
    {
        int a,b;
        a=fnd(s[i].u);
        b=fnd(s[i].v);
        if(s[i].w>=cst)break;
        if(a!=b)
        {
            coun++;
            par[a]=b;
            sum+=s[i].w;
            if(coun==n-1)break;
        }
    }
    sum=sum+(n-coun)*cst;
    return sum;
}
int main()
{
    int tst,tt=1;
    sf1(tst);
    while(tst--)
    {
        sf3(n,edge,cst);
        for(int i=0;i<edge;i++)
        {
            sf3(s[i].u,s[i].v,s[i].w);
        }
        sort(s,s+edge,comp());
        long long  ss;
        ss=scc();
        pfc(tt++);
        pf2(ss,n-coun);
    }
    return 0;
}


