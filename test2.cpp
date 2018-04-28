/*
ID: hremon32
PROG:
LANG: C++11
*/
#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>

using namespace std;
#define pfcn(x) printf("Case %d:\n",x)
#define pfc(x) printf("Case %d: ",x)
#define sf1(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d%d",&x,&y)
#define sf3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define pf1(x) printf("%d\n",x)
#define pf2(x,y) printf("%d %d\n",x,y)
#define pf3(x,y,z) printf("%d %d %d\n",x,y,z)
#define mod 1000000007
#define ll long long
#define llu unsigned long long
#define pii pair<int,int>
#define PI acos(-1.00)
#define pb push_back
#define ppb pop_back
int n,m;
struct lol
{
    int x;
    int y;
    int z;
};
vector<lol>g;
vector<int>graph[100005],cost[100005];
int par[100055];
int parent[100005];
int dam[100005];
int sp[50055][20];
int dist[50055][20];
int level[100005];
int comp(lol a,lol b)
{
    return a.z<b.z;
}
int found(int p)
{
    if(par[p]==p)return p;
    else
    {
        //par[p]=found(par[p]);
        return (par[p]=found(par[p]));
    }
}
void mst()
{
    for(int i=1; i<=n; i++)par[i]=i;
    for(int i=0; i<m; i++)
    {
        int u,v,uparent,vparent,cs;
        u=g[i].x;
        v=g[i].y;
        cs=g[i].z;
        uparent=found(u);
        vparent=found(v);
        if(uparent!=vparent)
        {
            par[uparent]=vparent;
            graph[u].pb(v);
            graph[v].pb(u);
            cost[u].pb(cs);
            cost[v].pb(cs);
        }
    }
}
void dfs( int node,int from,int depth)
{
    parent[node]=from;
    level[node]=depth;
    for(int i=0; i<graph[node].size(); i++)
    {
        int child=graph[node][i];
        if(child==from)continue;
        dam[child]=cost[node][i];
        dfs(child,node,depth+1);
    }

}
void precal()
{
    for(int i=0; i<=n; i++)for(int j=0; (1<<j)<=n; j++)
        {
            sp[i][j]=-1;
        }
    parent[1]=-1;
    dam[1]=-1;
    for(int i=1; i<=n; i++)
    {
        sp[i][0]=parent[i];
        dist[i][0]=dam[i];
        //cout<<dist[i][0]<<endl;
    }
    for(int kk=1; (1<<kk)<=n; kk++)
    {
        for(int r=1; r<=n; r++)
        {
            if(sp[r][kk-1]!=-1)
            {
                sp[r][kk]=sp[sp[r][kk-1]][kk-1];
                dist[r][kk]=max(dist[r][kk-1],dist[sp[r][kk-1]][kk-1]);
            }
        }
    }
}
int query(int u,int v)
{
    int ans=0;
    if(level[u]<level[v])swap(u,v);
    int lg=1;
    while(1)
    {
        if(1<<(lg+1)>level[u])break;
        lg++;
    }
    for(int kk=lg; kk>=0; kk--)
    {
        if(level[u]-(1<<kk)>=level[v])
        {
            ans=max(ans,dist[u][kk]);
            //cout<<ans<<"    ghhh     "<<dist[u][kk]<<endl;
            u=sp[u][kk];
        }
    }
    if(u==v)return ans;
    for(int kk=lg; kk>=0; kk--)
    {
        if(sp[u][kk]!=-1&&sp[v][kk]!=sp[u][kk])
        {
            ans=max(ans,dist[u][kk]);
            //cout<<ans<<"    ghhh  uuuuuuuuu    "<<dist[u][kk]<<endl;
            ans=max(ans,dist[v][kk]);
           // cout<<ans<<"    ghhh  vvvvvvvvvvv     "<<dist[v][kk]<<endl;
            u=sp[u][kk];
            v=sp[v][kk];
        }
    }
    ans=max(ans,dist[u][0]);
    ans=max(ans,dist[v][0]);
    return ans;
}
void clr()
{
    g.clear();
    memset(sp,-1,sizeof(sp));
    memset(dist,-1,sizeof(dist));
    for(int i=0; i<=n; i++)
    {
        graph[i].clear();
        cost[i].clear();
        par[i]=i;
        level[i]=-1;
    }
}
int main()
{
    // ios::sync_with_stdio(false);
    //ifstream fin ("");
    //ofstream fout ("");
    int tst,t=1;
    sf1(tst);
    while(tst--)
    {
        sf2(n,m);
        clr();
        int a,b,c,q;
        for(int i=0; i<m; i++)
        {
            sf3(a,b,c);
            g.pb(lol{a,b,c});
        }
        sort(g.begin(),g.end(),comp);
        mst();
        dfs(1,1,0);
        precal();
        sf1(q);
        pfcn(t++);
        while(q--)
        {
            sf2(a,b);
            pf1(query(a,b));
        }
    }
    return 0;
}


