#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test,t=1;
    cin>>test;
    while(test--)
    {
        int x1,x2,x,y1,y2,y,n;
        cin>>x1>>y1>>x2>>y2;
        cin>>n;
        printf("Case %d:\n",t++);
        while(n--)
        {
            cin>>x>>y;
            if(x1<=x&&x2>=x&&y1<=y&&y2>=y)printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
