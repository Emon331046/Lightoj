#include<bits/stdc++.h>
using namespace std;
#define pcs(x) printf("Case %d: ",x)
#define sf1(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d%d",&x,&y)
#define sf3(x,y,z) scanf("%d%d%d",&x,&y,&z)
int main()
{
    int test,t=1;
    sf1(test);
    while(test--)
    {
        char s[100];
        int l,i,j,flag=0;
        scanf("%s",&s);
        l=strlen(s);
        for(i=0,j=l-1; i<l/2; i++,j--)
        {
            if(s[i]!=s[j])
            {
                flag=1;
                break;
            }
        }
        pcs(t++);
        if(flag==1)printf("No\n");
        else printf("Yes\n");
    }
    return 0;
}

