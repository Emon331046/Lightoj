#include<bits/stdc++.h>

using namespace std;
map<int,int>smp,fmp;
int a[20001],flag,f,s;
vector<int> v[20003];
void bfs(int st)
{
    int level[20001];
    memset(level,-1,sizeof(level));
    queue<int>q;
    q.push(st);
    level[st]=1;
    fmp[st]=1;
    a[st]=1;
    f++;
    while(!q.empty())
    {
        int u;
        u=q.front();
        if(fmp[u]==1)
        {
            flag=2;
        }
        if(smp[u]==1)
        {
            flag=1;
        }
        q.pop();
        for(int i=0; i<v[u].size(); i++)
        {
            if(level[v[u][i]]==-1)
            {

                if(flag==1)
                {
                    f++;
                    fmp[v[u][i]]=1;
                }
                if(flag==2)
                {
                   s++;
                   smp[v[u][i]]=1;
                }
                level[v[u][i]]=1;
                a[v[u][i]]=1;
                q.push(v[u][i]);
            }
        }
    }
}
int main()
{
    int e,n,flag,test,tt=1;
    scanf("%d",&test);
    while(test--)
    {
        memset(a,-1,sizeof(a));
        int coun=0;
        scanf("%d",&n);
        while(n--)
        {
            int n1,n2;
            scanf("%d%d",&n1,&n2);
            v[n1].push_back(n2);
            v[n2].push_back(n1);
        }
        for(int i=1; i<20001; i++)
        {
            if(v[i].size()!=0&&a[i]==-1)
            {
                f=0;s=0;
                bfs(i);
                coun=coun+max(f,s);
                fmp.clear();
                smp.clear();
            }
        }
        printf("Case %d: %d\n",tt++,coun);
        for(int i=0; i<20001; i++)v[i].clear();
    }
    return 0;
}

