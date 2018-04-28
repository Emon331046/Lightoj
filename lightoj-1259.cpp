#include<bits/stdc++.h>
using namespace std;
bool a[10000000];
vector<int>pm;
void sieve()
{
    for(int i=3; i*i<10000000; i=i+2)
    {
        if(!a[i])
        {
            for(int j=i+i+i; j<10000000; j=j+i+i)a[j]=true;
        }
    }
    for(int i=3;i<10000000;i=i+2)if(!a[i])pm.push_back(i);
}
int main()
{
    sieve();
    int test,n,t=1;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        if(n==4)printf("Case %d: 1\n",t++);
        else
        {
            int coun=0;
            for(int i=0; pm[i]<n; i=i+1)
            {
                if(n-pm[i]<pm[i])break;
                if(a[n-pm[i]]==false&&a[pm[i]]==false)coun++;
            }
            printf("Case %d: %d\n",t++,coun);
        }
    }
    return 0;
}


