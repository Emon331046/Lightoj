#include<bits/stdc++.h>
using namespace std;
#define pii pair<int ,int >
int flag,n,m,vis[250][250];
vector<pii >v[250],h[250];
void bfs(char cell[250][250])
{
    int fx[]= {-1,1,0,0};
    int fy[]= {0,0,-1,1};
    int d=1;
    memset(vis,-1,sizeof(vis));
    while(h[d].size())
    {
        for(int i=0; i<v[d].size(); i++)
        {
            for(int j=0; j<4; j++)
            {
                int tx,ty;
                tx=v[d][i].first+fx[j];
                ty=v[d][i].second+fy[j];
                if(tx<n&&ty<m&&tx>=0&&ty>=0&&vis[tx][ty]==-1&&cell[tx][ty]=='.')
                {
                    vis[tx][ty]=1;
                    v[d+1].push_back(pii(tx,ty));
                }
            }
        }
        for(int i=0; i<h[d].size(); i++)
        {

            for(int j=0; j<4; j++)
            {
                int tx,ty;
                tx=h[d][i].first+fx[j];
                ty=h[d][i].second+fy[j];
                if((tx>=n-1||ty>=m-1||tx<=0||ty<=0)&&vis[tx][ty]==-1&&cell[tx][ty]=='.')
                {
                    flag=d+1;
                    break;
                }
                if(tx<n&&ty<m&&tx>=0&&ty>=0&&vis[tx][ty]==-1&&cell[tx][ty]=='.')
                {
                    vis[tx][ty]=1;
                    h[d+1].push_back(pii(tx,ty));
                }
            }
            if(flag!=-1)break;
        }
        if(flag!=-1)break;
        d++;
    }
}
int main()
{
    int a,b,c,d;
    int test,t=1;
    cin>>test;
    while(test--)
    {
        char cell[250][250];
        cin>>n>>m;
        int i,j;
        c=-1;
        d=-1;
        flag=-1;
        for(i=0; i<n; i++)
        {
            for(j=0; j<m; j++)
            {
                cin>>cell[i][j];
                if(cell[i][j]=='J')
                {
                    if(i==0||j==0||i==n-1||j==m-1)flag=1;
                    h[1].push_back(pii(i,j));
                }
                else if(cell[i][j]=='F')
                {
                    v[1].push_back(pii(i,j));
                }
            }
        }
        if(flag==-1)bfs(cell);
        if(flag==-1)printf("Case %d: IMPOSSIBLE\n",t++);
        else printf("Case %d: %d\n",t++,flag);
        for(int i=0;i<250;i++)
        {
            v[i].clear();
            h[i].clear();
        }
    }
    return 0;
}
