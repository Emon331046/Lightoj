#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test,t=1,i;
    scanf("%d",&test);
    while(test--)
    {
        long long n,m,k;
        scanf("%lld%lld",&n,&m);
        long long s[100000],d=0;
        k=n-m;
        printf("Case %d:",t++);
        if(n==0&&m==0)printf(" 1");
        else if(k<=m)printf(" impossible");
        else
        {
            int st=sqrt(k);
            s[d]=1;
            d++;
            if(k!=1)
            {
                s[d]=k;
                d++;
            }
            if(st*st==k&&k!=1)
            {
                s[d]=st;
                d++;
            }
            for(i=2; i<st; i++)
            {

                if(k%i==0)
                {
                    s[d]=i;
                    d++;
                    s[d]=k/i;
                    d++;
                }
            }
            sort(s,s+d);
            for(i=0; i<d; i++)if(s[i]>m)printf(" %lld",s[i]);
        }
        printf("\n");
    }
    return 0;
}
