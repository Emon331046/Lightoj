#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[]= {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
    int s[101][101]= {0};
    int temp;
    for(int j=2; j<101; j++)
    {
        for(int i=0; a[i]<=j; i++)
        {
            temp=a[i];
            while(1)
            {
                s[j][a[i]]=s[j][a[i]]+(j/temp);
                temp=temp*a[i];
                if(temp>j)break;
            }
        }
    }
    int test,d=1,n;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        printf("Case %d: %d = %d (%d)",d++,n,a[0],s[n][a[0]]);
        for(int i=1;a[i]<=n;i++)printf(" * %d (%d)",a[i],s[n][a[i]]);
        printf("\n");
    }
    return 0;
}
