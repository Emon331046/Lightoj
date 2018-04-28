#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long test,t=1,a[4];
    cin>>test;
    while(test--)
    {
        double ans;
        cin>>a[0]>>a[1]>>a[2];
        sort(a,a+3);
        ans=(a[0]*a[0])+(a[1]*a[1]);
        ans=sqrt(ans);
        if(a[2]==ans)printf("Case %d: yes\n",t++);
        else printf("Case %d: no\n",t++);
    }
return 0;
}
