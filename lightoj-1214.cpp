#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long test,n,r,t=1;
    char s[10000];
    scanf("%lld%*c",&test);
    while(test--)
    {
        scanf("%s%lld%*c",s,&n);
        n=abs(n);
        int l,d=0;
        r=0;
        l=strlen(s);
        if(s[0]=='-')d++;
        for(int i=d;i<l;i++)
        {
            r=((r*10)+s[i]-'0')%n;
        }
        if(r==0)printf("Case %d: divisible\n",t++);
        else printf("Case %d: not divisible\n",t++);
    }
    return 0;
}

