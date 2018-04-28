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
long long inf = 214748364;
int dis[3][5005],n,flag[3][5005];
vector<pii>g[5005];
struct lol
{
    int tt;
    int cs;
    int uu;
};
class comp
{
public:
    bool operator()(lol a,lol b)
    {
        return a.cs>b.cs;
    }

};

void dijkstra(int ss)
{
    for(int i=0; i<=n; i++)
    {
        dis[1][i]=99999999;
        dis[2][i]=99999999;
        flag[1][i]=0;
        flag[2][i]=0;
    }
    priority_queue< lol ,vector<lol>, comp >q;
    dis[1][ss]=0;
    dis[2][ss]=99999999;
    q.push(lol{1,0,ss});
    while(!q.empty())
    {
        int u,t,w,v;
        t=q.top().tt;
        u=q.top().uu;
        q.pop();
        if(flag[t][u]==1)continue;
        flag[t][u]=1;
        //cout<<u<<endl;
        for(int i=0; i<g[u].size(); i++)
        {

            v=g[u][i].first;
            w=g[u][i].second;
            int fl=0;
            if(dis[t][u]+w<dis[1][v])
            {
                dis[2][v]=dis[1][v];
                dis[1][v]=dis[t][u]+w;
                q.push(lol{2,dis[2][v],v});
                q.push(lol{1,dis[1][v],v});

            }
            /*if(u==v&&dis[u]==0)
            {
                sec[v]=dis[u]+w;
                printf("chq");
                pf1(sec[v]);
                pf1(v);
            }*/
            else if(dis[t][u]+w<dis[2][v]&&dis[t][u]+w>dis[1][v])
            {
                dis[2][v]=dis[t][u]+w;
                q.push(lol{2,dis[2][v],v});
            }
        }
    }
}
int main()
{

    int tst,tt=1;
    cin>>tst;
    while(tst--)
    {
        int m;
        sf2(n,m);
        int u,v,w,i;
        while(m--)
        {
            sf3(u,v,w);
            g[u].push_back(pii(v,w));
            g[v].push_back(pii(u,w));
        }
        int ss=1;
        dijkstra(ss);
        pfc(tt++);
        pf1(dis[2][n]);
        for(i=0; i<=n; i++)g[i].clear();
    }
    return 0;
}

