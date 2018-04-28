#include<bits/stdc++.h>
using namespace std;
#define pcs(x) printf("Case %d: ",x)
#define sf1(x) scanf("%d",&x)
#define sf2(x,y) scanf("%lld%lld",&x,&y)
#define sf3(x,y,z) scanf("%d%d%d",&x,&y,&z)
int main()
{
    int test,t=1;
    sf1(test);
    while(test--)
    {
        long long n,m,ans;
        sf2(n,m);
        ans=m*m*(n/(2*m));
        pcs(t++);
        printf("%lld\n",ans);
    }
    return 0;
}


