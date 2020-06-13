#include <bits/stdc++.h>
using namespace std;

void func()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(i==1 && j==m)
            {
                cout<<"W";
            }
            else
            {
                cout<<"B";
            }
        }
        cout<<"\n";
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i+=1)
        func();
    return 0;
}