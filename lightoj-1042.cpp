#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long i,n,j,test,t=1;
    cin>>test;
    while(test--)
    {
        cin>>n;
        int a[1000]={0};
        i=0;
        while(n!=0)
        {
            a[i]=n%2;
            n=n/2;
            i++;
        }
        for(j=0;j<i;j++)
        {
            if(a[j+1]==0&&a[j]==1)
            {
                swap(a[j],a[j+1]);
                break;
            }
        }
        long long ans=0;
        for(j=0;j<i;j++)
        {
            ans=ans+(a[j]*pow(2,j));
        }
        cout<<ans<<endl;
    }
    return 0;
}
