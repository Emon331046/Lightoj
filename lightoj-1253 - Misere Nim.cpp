
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
    int tst,t=1;
    cin>>tst;
    while(tst--)
    {
        int n;
        cin>>n;
        long long ans=0,x;
        int flag=0;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            if(x>1)flag=1;
            ans=ans ^ x;
        }
        if(flag==0)
        {
            if(n%2==0)cout<<"Case "<<t++<<": Alice"<<endl;
            else cout<<"Case "<<t++<<": Bob"<<endl;
        }
        else if(ans>0)cout<<"Case "<<t++<<": Alice"<<endl;
        else cout<<"Case "<<t++<<": Bob"<<endl;
    }
    return 0;
}


