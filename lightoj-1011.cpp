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
int n,sum=0,mx=0;
int a[20][20],f[20];
void func(int i,int )
{
    if(i==n)
    {
        return 0;
    }
    for(int j=0; j<n; j++)
    {
        if(f[j]==0)
        {
            sum+=a[i][j];
            f[j]=1;
            func(i+1);
            sum-=a[i][j];
        }
        f[j]=0;
    }
}
int main()
{
    int tst,tt=1;
    sf1(tst);
    while(tst--)
    {
        mx=0;
        sum=0;
        sf1(n);
        for(int i=0; i<n; i++)for(int j=0; j<n; j++)sf1(a[i][j]);
        memset(f,0,sizeof(f));
        func(0);
        pfc(tt++);
        cout<<mx<<endl;
    }
    return 0;
}
