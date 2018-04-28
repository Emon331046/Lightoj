
/*
ID: hremon32
PROG:
LANG: C++11
*/
#include<iostream>
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
string pattern,text;
int a[1000010];
int kmp()
{
    string text=pattern;
    reverse(pattern.begin(),pattern.end());
    int now=0,cnt=0,mx=0;
    a[0]=0;
    for(int i=1; i<pattern.size(); i++)
    {
        while(now!=0&&pattern[now]!=pattern[i])now=a[now-1];
        if(pattern[now]==pattern[i])a[i]=++now;
        else a[i]=now;
    }
    now=0;
    for(int i=0; i<text.size(); i++)
    {
        while(now!=0&&pattern[now]!=text[i])now=a[now-1];
        if(text[i]==pattern[now])now++;
    }
    return (2*text.size()-now);
}
int main()
{
    ios::sync_with_stdio(false);
    int tst,t=1;
    cin>>tst;
    while(tst--)
    {
        cin>>pattern;
        cout<<"Case "<<t++<<": ";
        cout<<kmp()<<endl;
    }
    return 0;
}



