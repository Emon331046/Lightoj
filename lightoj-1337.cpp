#include<bits/stdc++.h>
using namespace std;
string s[501];
int coun,n,m,mm,v[501][501],ans[501][501];
char ch;
void dfs(int x,int y)
{
    v[x][y]=1;
    ans[x][y]=mm;
    if(s[x][y]=='C')
    {
        coun++;
    }
    if(x-1>=0&&(s[x-1][y]!='#')&&v[x-1][y]==-1)
    {
        dfs(x-1,y);
    }
    if(y-1>=0&&(s[x][y-1]!='#')&&v[x][y-1]==-1)
    {
        dfs(x,y-1);
    }
    if(y+1<n&&(s[x][y+1]!='#')&&v[x][y+1]==-1)
    {
        dfs(x,y+1);
    }
    if(x+1<m&&(s[x+1][y]!='#')&&v[x+1][y]==-1)
    {
        dfs(x+1,y);
    }
}
int main()
{
    int test,j,i,a,t=1;
    cin>>test;
    while(test--)
    {
        vector<int>vt;
        int b,c;
        memset(ans,-1,sizeof(ans));
        memset(v,-1,sizeof(v));
        mm=0;
        printf("Case %d:\n",t++);
        cin>>m>>n>>a;
        for(i=0; i<m; i++)cin>>s[i];
        for(i=0; i<m; i++)
        {
            for(j=0; j<n; j++)
            {
                if(v[i][j]==-1&&s[i][j]!='#')
                {
                    coun=0;
                    dfs(i,j);
                    vt.push_back(coun);
                    mm++;
                }
            }
        }
        for(i=0; i<a; i++)
        {
            cin>>b>>c;
            printf("%d\n",vt[ans[b-1][c-1]]);
        }
        vt.clear();
    }
    return 0;
}

