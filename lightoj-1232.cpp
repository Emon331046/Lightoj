#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
int dp[10010];
int main()
{
    int test,t=1,i,j,k;
    scanf("%d",&test);
    while(test--)
    {

        int coin[105],n,m;
        scanf("%d%d",&n,&k);
        for(i=0; i<=k; i++) dp[k]=0;

        for(i=0; i<n; i++)
        {
            scanf("%d",&coin[i]);
        }

        memset(dp,0,sizeof(dp));

        dp[0]=1;

        for(i=0; i<n; i++)
        {
            for(j=coin[i]; j<=k; j++)
            {

                dp[j]=(dp[j]+dp[j-coin[i]])%mod;
            }
        }

        int ans=dp[k]%mod;

        printf("Case %d: %d\n",t++,ans);
    }
    return 0;
}

