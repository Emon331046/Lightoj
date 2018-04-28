#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long a,b,i,j,test,t=1;
    cin>>test;
    while(test--)
    {
        cin>>b>>a;
        long long temp,n,m,coun1=0,coun2=0,sum;
        b=b-1;
        n=a/3;
        coun1=n*2;
        if(a%3==2)coun1++;
        m=b/3;
        coun2=m*2;
        if(b%3==2&&b!=0)coun2=coun2+1;
        long long int nnn;
        nnn=coun1-coun2;
        printf("Case %lld: %lld\n",t++,nnn);
    }
    return 0;
}
