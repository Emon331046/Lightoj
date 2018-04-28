#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test,t=1;
    long long a,b,c,d;
    cin>>test;
    while(test--)
    {
        cin>>a;
        printf("Case %d: ",t++);
        if(a%2==0)
        {
            b=1;
            while(a%2==0)
            {
                b=b*2;
                a/=2;
            }
            printf("%lld %lld\n",a,b);
        }
        else printf("Impossible\n");
    }
}
