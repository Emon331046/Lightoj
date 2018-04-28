#include<bits/stdc++.h>
using namespace std;
#define pcs(x) printf("Case %d: ",x)
#define sf1(x) scanf("%d",&x)
#define sf2(x,y) scanf("%d%d",&x,&y)
#define sf3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define sf4(x,y,z,m) scanf("%d%*c%d%*c%d%*c%d",&x,&y,&z,&m)

int main()
{
    int test,t=1;
    sf1(test);
    while(test--)
    {
        int n1,n2,n3,n4,m1,m2,m3,m4,a1=0,a2=0,a3=0,a4=0;
        sf4(n1,n2,n3,n4);
        sf4(m1,m2,m3,m4);
        int d=0;
        while(d!=8)
        {
            int temp;
            temp=pow(2,d);
            a1+=(m1%10)*temp;
            a2+=(m2%10)*temp;
            a3+=(m3%10)*temp;
            a4+=(m4%10)*temp;
            m1/=10;
            m2/=10;
            m3/=10;
            m4/=10;
            d++;
        }
        pcs(t++);
        if(n1==a1&&a2==n2&&a3==n3&&n4==a4)printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}



