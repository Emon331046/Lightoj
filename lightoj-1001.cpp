#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int s[100],e[100];
int main()
{
    int test,t=1;
    cin>>test;
    while(test--)
    {
        long long r,a,b,ans;
        cin>>a;
        ans=a-10;
        if(ans<0)
        {
            ans=0;
        }
        else
        {

            ans=a-10;
            a=10;
        }
        printf("%lld %lld\n",a,ans);
    }
    return 0;
}


