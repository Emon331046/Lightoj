#include<bits/stdc++.h>
using namespace std;
#define pcs(x) printf("Case %d:",x)
int main()
{
    int test,t=1;
    cin>>test;
    while(test--)
    {
        int n;
        long long d,ans=0;
        cin>>n;
        string s;
        pcs(t++);
        cout<<endl;
        while(n--)
        {
            cin>>s;
            if(s[0]=='d')
            {
                cin>>d;
                ans+=d;
            }
            if(s[0]=='r')cout<<ans<<endl;
        }
    }
    return 0;
}
