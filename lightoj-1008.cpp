#include<bits/stdc++.h>
using namespace std;
#define pi acos(-1)
int main()
{
    int test,t=1;

    cin>>test;
    while(test--)
    {
        long long r,a,b,ans,c;
        cin>>a;
        b=sqrt(a);
        ans=b*b;
        if(ans!=a)b=b+1;
        ans=((b*b)+(b-1)*(b-1)+1)/2;
        if(b%2==1)
        {
            if(a>ans)
            {
                r=b;
                c=b*b+1-a;
            }
            else if(a<ans)
            {
                c=b;
                r=a-(b-1)*(b-1);
            }
            else c=r=b;

        }
        if(b%2==0)
        {
            if(a<ans)
            {
                r=b;
                c=a-(b-1)*(b-1);
            }
            else if(a>ans)
            {
                c=b;
                r=b*b-a+1;;
            }
            else c=r=b;

        }
        printf("Case %d: %lld %lld\n",t++,c,r);
    }
    return 0;
}


