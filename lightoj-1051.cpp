#include<bits/stdc++.h>
using namespace std;
char c[100];
int main()
{
    int test,n,i,j,l,t=1;
    cin>>test;
    while(test--)
    {
        int vowel=0,cons=0,vowel1=0,cons1=0;
        cin>>c;
        l=strlen(c);
        int flag=0,tlag=0,glag=0;

        if(c[0]=='?')
        {
            vowel=0;
            cons=0;
            vowel1=1;
            cons1=1;
        }
        else if(c[0]=='E'||c[0]=='U'||c[0]=='I'||c[0]=='O'||c[0]=='A')
        {
            vowel++;
            cons=0;
            vowel1++;
            cons1=0;
        }
        else
        {
            cons++;
            vowel=0;
            cons1++;
            vowel1=0;
        }
        for(i=1; i<l; i++)
        {

            if(c[i]=='?')
            {
                cons1++;
                vowel1++;
                if(cons==4)
                {
                    vowel++;
                    cons=0;
                }
                else if(vowel==2)
                {
                    cons++;
                    vowel=0;
                }
                else
                {
                    cons=0;
                    vowel=0;
                }
            }
            else if(c[i]=='E'||c[i]=='U'||c[i]=='I'||c[i]=='O'||c[i]=='A')
            {
                vowel1++;
                cons1=0;
                vowel++;
                cons=0;
            }
            else
            {
                cons1++;
                vowel1=0;
                vowel=0;
                cons++;
            }
            if(vowel1>=3||cons1>=5)
            {
                tlag=1;
            }
            if(vowel>=3||cons>=5)glag=1;
        }
        printf("Case %d: ",t++);
        if(glag)printf("BAD\n");
        else if(tlag==1)printf("MIXED\n");
        else printf("GOOD\n");
    }
    return 0;
}

