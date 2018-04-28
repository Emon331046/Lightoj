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
vector<int>g[10005];
int col[10005],coun;
stack<int>st;
void dfs(int u)
{
    col[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        if(col[g[u][i]]==0)dfs(g[u][i]);
    }
    st.push(u);
}
void adfs(int u)
{
    col[u]=1;
    for(int i=0;i<g[u].size();i++)
    {
        if(col[g[u][i]]==0)adfs(g[u][i]);
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
        for(int i=1;i<=n;i++)g[i].clear();
        while(m--)
        {
            int a,b;
            sf2(a,b);
            g[a].pb(b);
        }
        coun=0;
        memset(col,0,sizeof(col));
        for(int i=1;i<=n;i++)
        {
            if(col[i]==0)dfs(i);
        }
        memset(col,0,sizeof(col));
        while(!st.empty())
        {
            int tp;
            tp=st.top();
            st.pop();
            if(col[tp]==0)
            {
                coun++;
                adfs(tp);
            }
        }
        pfc(t++);
        pf1(coun);
    }
    return 0;
}
