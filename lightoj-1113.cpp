#include<bits/stdc++.h>
using namespace std;
int main()
{
    int test,t=1;
    cin>>test;
    while(test--)
    {
        char s[100];
        stack<string> st,mp;
        char s1[]="http://www.lightoj.com/";
        st.push(s1);
        printf("Case %d:\n",t++);
        while(cin>>s)
        {
            if(s[0]=='V')
            {
                char a[100];
                cin>>a;
                printf("%s\n",a);
                st.push(a);
                while(!mp.empty())
                {
                    mp.pop();
                }
            }
            else if(s[0]=='F')
            {
                if(mp.empty())printf("Ignored\n");
                else
                {
                    cout<<mp.top()<<endl;
                    st.push(mp.top());
                    mp.pop();
                }
            }
            else if(s[0]=='B')
            {
                if(st.empty()||st.size()==1)printf("Ignored\n");
                else
                {
                    mp.push(st.top());
                    st.pop();
                    cout<<st.top()<<endl;

                }
            }
            else break;
        }
    }
    return 0;
}
