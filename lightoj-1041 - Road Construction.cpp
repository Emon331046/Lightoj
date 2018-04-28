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
int par[200],d,edge,tt=1;
struct lol
{
    int uu;
    int vv;
    int w;
} s[105];
class comp
{
public:
    bool operator()(lol a,lol b)
    {
        return a.w<b.w;
    }
};
void makeset()
{
    for(int i=1; i<=d; i++)par[i]=i;
}
int fnd(int m)
{
    if(par[m]==m)return m;
    else
    {
        par[m]=fnd(par[m]);
        return par[m];
    }
}
void scc()
{
    int cnt=0;
    int sum=0;
    for(int i=0; i<edge; i++)
    {
        int a,b,c;
        a=fnd(s[i].uu);
        b=fnd(s[i].vv);
        c=s[i].w;
        if(a!=b)
        {
            par[a]=b;
            sum+=c;
            cnt++;
            if(cnt==d-1)break;
        }
    }
    pfc(tt++);
    if(cnt<d-1)printf("Impossible\n");
    else printf("%d\n",sum);
}
int main()
{
    int tst;
    cin>>tst;
    while(tst--)
    {
        cin>>edge;
        int z;
        d=0;
        map<string,int>mp;
        for(int i=0; i<edge; i++)
        {
            string x,y;
            cin>>x>>y>>z;
            if(mp[x]==0)
            {
                d++;
                mp[x]=d;
            }
            if(mp[y]==0)
            {
                d++;
                mp[y]=d;
            }
            s[i].uu=mp[x];
            s[i].vv=mp[y];
            s[i].w=z;
        }
        sort(s,s+edge,comp());
        makeset();
        scc();
        mp.clear();
    }
    return 0;
}
