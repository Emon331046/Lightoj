#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,f,s[100000];
long long fn(long long n){
    if(s[n]!=-1)return s[n];
    else {
        s[n]=(fn((n-1))+fn(n-2)+fn(n-3)+fn(n-4)+fn(n-5)+fn(n-6))%10000007;
        return s[n];
    }
}
int main()
{
    long long n,test,ans,t=0,i;
    scanf("%lld",&test);
    while(t<test){
        memset(s,-1,sizeof(s));
        scanf("%lld %lld %lld %lld %lld %lld %lld",&a,&b,&c,&d,&e,&f,&n);
        s[0]=a;
        s[1]=b;
        s[2]=c;
        s[3]=d;
        s[4]=e;
        s[5]=f;
        ans=fn(n)%10000007;
        printf("Case %lld: %lld\n",++t,ans);
    }
return 0;
}
