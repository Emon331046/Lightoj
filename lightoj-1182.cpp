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

            b=0;
            while(a!=0)
            {
                b+=(a%2);
                a/=2;
            }
            if(b%2==1)printf("odd\n");
            else printf("even\n");
    }
    return 0;
}

