#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main()
{
    int test,t=1;

    cin>>test;
    while(test--)
    {
        double r,a,b,ans;
        cin>>r;

        a=pi*r*r;
        b=(2*r)*(2*r);
        ans=b-a;
        printf("Case %d: %.2lf\n",t++,ans);
    }
    return 0;
}

