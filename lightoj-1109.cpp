#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
int a[1010];
vector<pair<int,int> >v;
vector<int>prime;
bool comp(pii a,pii b)
{
    if(a.first<b.first)return true;
    else if(a.first==b.first)return a.second>b.second;
    else return false;
}
void func()
{
    int i,j,n;
    for(i=1000;i>1;i--)
    {
        n=i;
        int ans=1,coun;
        for(j=0;prime[j]*prime[j]<=n;j++)
        {
            if(n%prime[j]==0)
            {
                coun=1;
                while(n%prime[j]==0)
                {
                    coun++;
                    n=n/prime[j];
                }
                ans=ans*coun;
            }
        }
        if(n>1)ans=ans*2;

        v.push_back(pii(ans,i));
    }
    v.push_back(pii(1,1));
    sort(v.begin(),v.end(),comp);
}
void sieve()
{
    int i,j;
    for(i=3;i<1009;i=i+2)
    {
        int k=2*i;
        if(a[i]==0)for(j=i+k;j<1009;j=j+k)a[j]=1;
    }
    prime.push_back(2);
    for(i=3;i<1009;i=i+2)if(a[i]==0)prime.push_back(i);
}
int main()
{
    int test,t=1;
    sieve();
    func();
    cin>>test;
    while(test--)
    {
        int l;
        cin>>l;
        printf("Case %d: %d\n",t++,v[l-1].second);
    }
    return 0;
}



