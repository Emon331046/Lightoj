#include<bits/stdc++.h>
using namespace std;
int a[1001],coun,endd;
vector<int>v[1001];
int bfs(int start)
{
    int vis[1001]= {0};
    vis[start]=1;
    queue<int>q;
    q.push(start);
    while(!q.empty())
    {
        int top;
        top=q.front();
        q.pop();
        vis[top]=1;
        for(int i=0; i<v[top].size(); i++)
        {
            cout<<v[top][i]+top<<' '<<endl;;
            if(top+v[top][i]==endd)coun++;
            if(top+v[top][i]<endd&&vis[v[top][i]]==0)
            {
                q.push(top+v[top][i]);
            }
        }
    }
    return coun;
}
void func()
{
    for(int i=2; i<1001; i<i++)
    {
        if(a[i]==0)
        {
            for(int j=i+i; j<1001; j=i+j)
            {
                a[j]=1;
                v[j].push_back(i);
            }
        }
    }
}
int main()
{
    func();
    int m,n,test,t=1;
    cin>>test;
    while(test--)
    {
        cin>>m>>endd;
        if(m==endd)printf("Case %d: 0\n",t++);
        else
        {
            coun=0;
            int d;
            d=bfs(m);
            if(d==0)printf("Case %d: -1\n",t++);
            else printf("Case %d: %d\n",t++,d);
        }
    }
    return 0;
}
