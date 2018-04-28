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
int cnt[1005],vis[1005],coun,k,n,m;
vector<int>g[1005];
vector<int>vv;
void dfs(int u)
{
    vis[u]=1;
    cnt[u]++;
    if(cnt[u]==k)coun++;
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(vis[v]==0)
        {
            dfs(v);
        }
    }
}
int main()
{
    int tst,tt=1;
    sf1(tst);
    while(tst--)
    {
        sf3(k,n,m);
        coun=0;
        memset(cnt,0,sizeof(cnt));
        int kk=k;
        while(kk--)
        {
            int a;
            sf1(a);
            vv.pb(a);
        }
        while(m--)
        {
            int u,v;
            sf2(u,v);
            g[u].pb(v);
        }
        for(int i=0;i<vv.size();i++)
        {
            memset(vis,0,sizeof(vis));
            dfs(vv[i]);
        }
        pfc(tt++);
        pf1(coun);
        vv.clear();
        for(int i=0;i<=n;i++)g[i].clear();
    }
    return 0;

}
