#include <bits/stdc++.h>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);
#define ll long long int
using namespace std;
void func()
{
    string s;
    cin>>s;
    int n=s.length();
    int preS[n]={0};
    int i=1,len=0;
    while(i<n)
    {
        if(s[i]==s[len])
        {
            len++;
            preS[i]=len;
            i++;
        }
        else
        {
            if(len!=0)
                len=preS[len-1];
            else
            {
                preS[i]=0;
                i++;
            }
        }
    }
    for(int i=0;i<n;i++)
        cout<<preS[i]<<" ";

    cout<<endl;
}
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {
        func();
    }

    return 0;
}