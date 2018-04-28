
/*
ID: hremon32
PROG:
LANG: C++11
*/
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>

using namespace std;
#define mod 1000000007
#define ll long long
#define llu unsigned long long
#define pii pair<int,int>
#define PI acos(-1.00)
#define pb push_back
#define ppb pop_back

int main()
{
    ios::sync_with_stdio(false);
    ifstream fin ("");
    ofstream fout ("");

    return 0;
}


int main()
{
    int m,n,test,t=1;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d%d",&n,&m);
        double b;
        int a;
        if(n==1||m==1)
        {
            a=n*m;
        }
        else if(n==2||m==2)
        {
            if(n==2)
            {
                if(m%4==3)a=m+1;
                else a=m+(m%4);
            }
            else
            {
                if(n%4==3)a=n+1;
                else a=n+(n%4);
            }
        }
        else
        {
            b=(double)(n*m)/2;
            a=ceil(b);
        }
        printf("Case %d: %d\n",t++,a);
    }
    return 0;
}
