#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int ans=0,mx;
int vis[100000];
vector< pii >p[ 30001];
void dfs(int u,int dist)
{
    vis[u]=1;
    if(dist>ans)
    {
        ans=dist;
        mx=u;
    }
        for(int i=0; i<p[u].size(); i++)if(vis[p[u][i].first]==0)
            {
                dfs(p[u][i].first,dist+p[u][i].second);
            }
    }
    int main()
    {
        int test,t=1,n;
        scanf("%d",&test);
        while(test--)
        {
            ans=-1;
            scanf("%d",&n);
            int u,v,w;
            int k=n;
            n--;
            while(n--)
            {
                scanf("%d%d%d",&u,&v,&w);
                p[u].push_back(pii(v,w));
                p[v].push_back(pii(u,w));
            }
            memset(vis,0,sizeof(vis));
            dfs(0,0);
            memset(vis,0,sizeof(vis));
            dfs(mx,0);
            printf("Case %d: %d\n",t++,ans);
            for(int i=0;i<k;i++)p[i].clear();
        }
        return 0;
    }
