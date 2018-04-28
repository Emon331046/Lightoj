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
int vis[20005],coun,col[20005];
vector<int>g[20005],f[20005],in_deg[20005],out_deg[20005];
stack<int>st;
void dfs(int u)
{
    vis[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(vis[v]==0)
        {
            dfs(v);
        }
    }
    st.push(u);
}
void mdfs(int u)
{
    vis[u]=1;
    col[u]=coun;
    for(int i=0; i<f[u].size(); i++)
    {
        int v=f[u][i];
        if(vis[v]==1&&col[u]!=col[v])
        {
            out_deg[col[v]].pb(col[u]);
            in_deg[col[u]].pb(col[v]);
        }
        if(vis[v]==0)
        {
            mdfs(v);
        }
    }
}
int main()
{
    int tst,t=1;
    sf1(tst);
    while(tst--)
    {
        int n,m;
        sf2(n,m);
        coun=0;
        memset(col,0,sizeof(col));
        for(int i=0; i<=n; i++)
        {
            f[i].clear();
            g[i].clear();
            in_deg[i].clear();
            out_deg[i].clear();
        }
        memset(vis,0,sizeof(vis));
        while(m--)
        {
            int u,v;
            sf2(u,v);
            g[u].pb(v);
            f[v].pb(u);
        }
        for(int i=1; i<=n; i++)
        {
            if(vis[i]==0)dfs(i);
        }
        memset(vis,0,sizeof(vis));
        while(!st.empty())
        {
            int tp;
            tp=st.top();
            st.pop();
            if(vis[tp]==0)
            {
                coun++;
                mdfs(tp);
            }
        }
        int cn=0;
        int ans=0,ans1=0;
        for(int i=1; i<=coun; i++)
        {
            if(out_deg[i].size()<1)
            {
                ans++;
            }
            if(in_deg[i].size()<1)ans1++;
        }
        ans=max(ans,ans1);
        //pfc(t++);
        if(coun==1)printf("0\n");
        else pf1(ans);
    }
    return 0;
}
