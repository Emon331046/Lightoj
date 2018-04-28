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
int timer=0,d[10005],low[10005],col[10005],root;
vector<int>g[10005];
set<int>s;
void dfs(int u,int p)
{
    low[u]=d[u]=timer++;
    int cnt=0;
    col[u]=1;
    for(int i=0; i<g[u].size(); i++)
    {
        int v=g[u][i];
        if(v==p)continue;
        if(col[v]==0)
        {
            cnt++;
            col[v]=1;
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=d[u]&&u!=1)
            {
                s.insert(u);//articulation point
            }
            //if(low[v]>d[u])be.insert(pii(u,v));//bridge edge
        }
        else if(col[v]==1)low[u]=min(low[u],d[v]);
        if(u==1&&cnt>1)
        {
            s.insert(u);
        }
    }
}
int main()
{
    int test,t=1,n,m;
    sf1(test);
    while(test--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<=n; i++)
        {
            g[i].clear();
            col[i]=0;
        }
        timer=0;
        s.clear();
        while(m--)
        {
            int u,v;
            sf2(u,v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
        dfs(1,1);
        //set<int>::iterator it;
        //for(it=s.begin(); it!=s.end(); it++)cout<<*it<<' ';
        //cout<<endl;
        pfc(t++);
        cout<<s.size()<<endl;
    }
    return 0;
}
