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
char s[150][150];
int vis[105][205],level[105][160],n;
int cnt,last;
int bfs(int x,int y)
{
    int fx[]= {1,-1,0,0};
    int fy[]= {0,0,1,-1};
    queue<pii>q;
    q.push(pii(x,y));
    vis[x][y]=1;
    level[x][y]=0;
    int top;
    top='A';
    cnt++;
    while(!q.empty())
    {
        int tx,ty;
        tx=q.front().first;
        ty=q.front().second;
        q.pop();
        for(int i=0; i<4; i++)
        {
            int sx,sy;
            sx=tx+fx[i];
            sy=ty+fy[i];
            if(sx>=0&&sx<n&&sy>=0&&sy<n&&vis[sx][sy]==0&&s[sx][sy]=='.')
            {
                vis[sx][sy]=1;
                level[sx][sy]=level[tx][ty]+1;
                q.push(pii(sx,sy));
            }
            if(isalpha(s[sx][sy])&&s[sx][sy]-top==1&&vis[sx][sy]==0)
            {
                top=s[sx][sy];
                cnt++;
                vis[sx][sy]=1;
                last=level[tx][ty]+1;
                level[sx][sy]=level[tx][ty]+1;
                q.push(pii(sx,sy));
            }
        }
    }
}

int main()
{
    int tst,tt=1;
    sf1(tst);
    while(tst--)
    {
        cin>>n;
        int gx,gy;
        cnt=0;
        last=0;
        int coun=0;
        memset(vis,0,sizeof(vis));
        for(int i=0; i<n; i++)for(int j=0; j<n; j++)
            {
                cin>>s[i][j];
                if(isalpha(s[i][j]))coun++;
                if(s[i][j]=='A')
                {
                    gx=i;
                    gy=j;
                }
            }
        bfs(gx,gy);
        pfc(tt++);
        //cout<<cnt<<coun<<endl;
        if(last&&coun==cnt)pf1(last);
        else printf("Impossible\n");
    }
    return 0;

}

