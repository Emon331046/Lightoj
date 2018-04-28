#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t=1,test,n,m,ans;
    cin>>test;
    while(test--)
    {
        ans=0;
        cin>>n;
        while(n--)
        {
            cin>>m;
            if(m>0)ans+=m;
        }
        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}
