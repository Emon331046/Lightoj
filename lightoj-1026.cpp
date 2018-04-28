#include<bits/stdc++.h>
using namespace std;
#define pfc(x) printf("Case %d:\n",x)
#define sf1(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d%d",&x,&y)
#define sf3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sf4(x,y,z,m) scanf("%d%d%d%d",&x,&y,&z,&m)
#define pf1(x) printf(" %d",x)
#define pf2(x,y) printf("%d %d\n",x,y)
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z)
#define pf4(x,y,z,m) printf("%d %d %d %d\n",x,y,z,m)
#define pii pair<long long,long long>
long long inf = 2147483647154869;
int timer=0,d[10005],low[10005],col[10005],root;
vector<int>g[10005];
set<pii>be;
priority_queue<pii>q;
void dfs(int u,int p)
{
    low[u]=d[u]=timer++;
    col[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(v==p)continue;
        if(col[v]==0)
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>d[u])
            {
                if(u<v)q.push(pii(-u,-v));
                else q.push(pii(-v,-u));
            }

        }
            else if(col[v]==1)low[u]=min(low[u],d[v]);
    }
}
int main()
{
    int test,t=1,n,m;
    sf1(test);
    while(test--)
    {
        scanf("%d",&n);
        for(int i=0; i<=n; i++)
        {
            g[i].clear();
            col[i]=0;
        }
        timer=0;
        be.clear();
        m=n;
        while(n--)
        {
            int u,v,k;
            scanf("%d%*c%*c",&u);
            scanf("%d%*c%*c",&k);
            for(int i=0; i<k; i++)
            {
                sf1(v);
                g[u].push_back(v);
                g[v].push_back(u);
            }
        }
        for(int i=0; i<m; i++)
        {
            if(col[i]==0)
            {
                dfs(i,i);
            }

        }
        pfc(t++);
        printf("%d critical links\n",q.size());
        while(!q.empty())
        {
            cout<<-q.top().first<<' '<<'-'<<' '<<-q.top().second<<endl;
            q.pop();
        }
    }
    return 0;
}


