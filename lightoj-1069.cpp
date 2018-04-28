#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test,t=1,n,m;
    cin>>test;
    while(test--)
    {
        int ans;
        cin>>n>>m;
        ans=19+(abs(m-n)*4)+(n*4);
        printf("Case %d: %d\n",t++,ans);
    }
return 0;
}

