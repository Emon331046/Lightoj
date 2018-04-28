#include<bits/stdc++.h>
using namespace std;
#define pfc(x) printf("Case %d: ",x)
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
long long d[100005];
int h[100005],flag[1000],n;
vector<pii>g[100005];
void dijkstra(int ss)
{
    d[ss]=0;
    priority_queue<pii>q;
    q.push(pii(0,ss));
    while(!q.empty())
    {
        int u,v,w,c;
        c=-q.top().first;
        u=q.top().second;
        q.pop();
        if(flag[u]==1)continue;
        flag[u]=1;
        for(int i=0; i<g[u].size(); i++)
        {
            int v,w;
            v=g[u][i].first;
            w=g[u][i].second;
            if(d[v]>d[u]&&d[v]>w)
            {
                if(d[u]<w)d[v]=w;
                else d[v]=d[u];
                q.push(pii(-d[v],v));

            }
        }
    }
}
int main()
{
    int m;
    int tt=1,test;
    sf1(test);
    while(test--)
    {
        sf2(n,m);
        int u,v,w,i;
        for(i=0; i<=n; i++)
        {
            d[i]=2147483647154869;
            g[i].clear();
            flag[i]=0;
        }
        while(m--)
        {
            sf3(u,v,w);
            g[u].push_back(pii(v,w));
            g[v].push_back(pii(u,w));
        }
        int ss;
        sf1(ss);
        dijkstra( ss);
        printf("Case %d:\n",tt++);
        for(int i=0; i<n; i++)
        {
            if(flag[i]==1)printf("%d\n",d[i]);
            else printf("Impossible\n");
        }
    }
    return 0;
}
