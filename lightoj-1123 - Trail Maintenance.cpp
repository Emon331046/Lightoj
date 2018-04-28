#include<bits/stdc++.h>
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
#define pii pair<int ,int >
int n,flag=0;
int par[10005];
struct lol
{
    int u;
    int v;
    int w;
} s[10005];
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

void mst(int edge)
{
    for(int i=1; i<=n; i++)par[i]=i;
    int sum=0;
    int coun=0;
    int a,b;
    int ff=1;
    for(int i=0; i<=edge; i++)
    {
        a=fnd(s[i].u);
        b=fnd(s[i].v);
        if(a==b)
        {
            ff=1;
            s[i].w=99999999;
            continue;
        }
        if(a!=b)
        {
            par[a]=b;
            coun++;
            sum+=s[i].w;
            if(coun==n-1)break;
        }
    }
    if(ff==1)sort(s,s+(edge+1),comp());
        pf1(sum);

}

void mst1(int edge)
{
    for(int i=1; i<=n; i++)par[i]=i;
    int sum=0;
    int coun=0;
    int a,b;
    for(int i=0; i<=edge; i++)
    {
        a=fnd(s[i].u);
        b=fnd(s[i].v);
        if(a==b)
        {
            s[i].w=99999999;
            continue;
        }
        if(a!=b)
        {
            par[a]=b;
            coun++;
            sum+=s[i].w;
            if(coun==n-1)break;
        }
    }
    if(coun==n-1)sort(s,s+(edge+1),comp());
    if(coun<n-1)printf("-1\n");
    else
    {
        flag=1;
        pf1(sum);
    }

}
int main()
{
    int tst,tt=1;
    sf1(tst);
    while(tst--)
    {
        int g;
        flag=0;
        sf2(n,g);
        pfc(tt++);
        for(int i=0; i<g; i++)
        {
           if(flag)
            {
                int a,b,c;
                sf3(a,b,c);
                s[n].u=a;
                s[n].v=b;
                s[n].w=c;
                int ct=n+1;
                sort(s,s+ct,comp());
                mst(n);
            }
            else
            {
                sf3(s[i].u,s[i].v,s[i].w);
                int x=i+1;
                sort(s,s+x,comp());
                mst1(i);
            }
        }
    }
    return 0;
}
