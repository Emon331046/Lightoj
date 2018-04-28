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
#define pii pair<int ,int >
int n,ans,edge;
int par[2505];
struct lol
{
    int u;
    int v;
    int w;
} s[2505];
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
    int coun=0,sum=0;
    for(int i=0;i<edge;i++)
    {
        int a,b;
        a=fnd(s[i].u);
        b=fnd(s[i].v);
        if(a!=b)
        {
            coun++;
            par[a]=b;
            sum+=s[i].w;
            if(coun==n-1)break;
        }
    }
    if(coun<n-1)sum=-1;
    return sum;
}
int main()
{
    int tst,tt=1;
    sf1(tst);
    while(tst--)
    {
        sf1(n);
        int m,d=0;
        ans=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                sf1(m);
                if(i!=j&&m!=0)
                {
                    s[d].u=i;
                    s[d].v=j;
                    s[d].w=m;
                    d++;
                }
                ans+=m;
            }
        }
        edge=d;
        sort(s,s+edge,comp());
        int ss;
        ss=scc();
        ans=ans-ss;
        pfc(tt++);
        if(ss!=-1)pf1(ans);
        else printf("-1\n");
    }
    return 0;
}

