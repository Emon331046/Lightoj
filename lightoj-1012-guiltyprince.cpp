#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int grid[1000][1000];
int n,m;
int bfs(int sx,int sy)
{
    int level[100][100];
    memset(level,0,sizeof(level));
    queue<pii>q;
    q.push(pii(sx,sy));
    int coun=1;
    int fx[]= {1,-1,0,0};
    int fy[]= {0,0,1,-1};
    level[sx][sy]=1;
    while(!q.empty())
    {

        pii top;
        top=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {

            int tx,ty;
            tx=top.first+fx[i];
            ty=top.second+fy[i];
            if(tx>=0&&tx<n&&ty>=0&&ty<m&&level[tx][ty]==0&&grid[tx][ty]==1)
            {
                level[tx][ty]=level[top.first][top.second]+1;
                q.push(pii(tx,ty));
                coun++;
            }
        }
    }
    return coun;
}

int main()
{
    int t=1;
    int test;
    char c[500][500];
    cin>>test;
    while(test--)
    {

        int a,b;
        cin>>m>>n;
        for(int i=0; i<n; i++)
        {

            for(int j=0; j<m; j++)
            {
                cin>>c[i][j];
                if(c[i][j]=='@')
                {
                    a=i;
                    b=j;
                    grid[i][j]=1;
                }
                else if(c[i][j]=='#')grid[i][j]=-1;
                else grid[i][j]=1;
            }
        }
        int ans=bfs(a,b);
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;

}
