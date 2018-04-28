#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test,n,flag,f=1;
    cin>>test;
    while(test--){
        flag=1;
        cin>>n;
        map<string ,int>mymap;
        int dd=0;
        while(n--){
                char s1[100],s2[100];
            cin>>s1>>s2;
            int temp1,temp2;
            if(strcmp(s1,s2)==0)flag=0;
          if(mymap.find(s1)==mymap.end()){
            mymap[s1]=dd++;
            mymap[s2]=dd++;
          }
          else if(mymap.find(s2)==mymap.end()){
            mymap[s2]=dd++;
          }
          else {
            temp1=mymap[s1];
            temp2=mymap[s2];
            if(temp2<=temp1)flag=0;
          }
        }
        if(flag==1)printf("Case %d: Yes\n",f++);
        else printf("Case %d: No\n",f++);
    }
    return 0;
}
