#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main()
{
    int test,t=1;
    cin>>test;
    while(test--)
    {
            double x,y,a,n;
            cin>>x>>y;
            n=360/(y*2)*pi;
            a=(sin(n/180)*x)/(1+sin(n/180));
            printf("Case %d: %.10lf\n",t++,a);
    }
    return 0;
}

