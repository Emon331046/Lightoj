/*
ID: hremon32
PROG:
LANG: C++11
*/
#include<bits/stdc++.h>
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
int sparse[22][100055];
int arr[100055];
int query(int from,int to )
{
    int lg=log2(to-from+1);
    int ans=min( arr [ sparse [ lg  ][ from ] ],arr[ sparse[ lg ] [  to - (1<< lg) + 1 ] ] );
    return ans;
}
void precalculation(int n)
{
    for(int i=0; i<n; i++)sparse [ 0 ][i]=i;
    for(int j=1; (1<<j) <=n; j++)
    {
        int dif=1<<j;
        for(int i=0 ; i+dif - 1 <n ; i++ )
        {
            if(arr [ sparse [ j-1] [ i ] ] <= arr[ sparse[ j-1][ i+ (1<<(j-1)) ] ] )
            {
                sparse [ j ][ i ] = sparse[ j-1] [ i ] ;
            }
            else  sparse[ j ] [ i ] = sparse [ j-1][ i+ (1<<( j-1)) ] ;
        }
    }
}
int main()
{
    //ios::sync_with_stdio(false);
    //ifstream fin ("");
    //ofstream fout ("");
    int tst,t=1,n,q;
    scanf("%d",&tst);
    while(tst--)
    {
        scanf("%d%d",&n,&q);
        for(int i=0; i<n; i++)scanf("%d",&arr[i]);
        precalculation(n);
        int x,y;
        printf("Case %d:\n",t++);
        for(int i=0; i<q; i++)
        {
            scanf("%d%d",&x,&y);
             printf("%d\n",query(x-1,y-1));
        }
    }
    return 0;
}



