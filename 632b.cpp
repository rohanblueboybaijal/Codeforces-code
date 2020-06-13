#include <bits/stdc++.h>
using namespace std;

void func()
{
    int n;
    cin>>n;
    int temp;
    vector<int> a,b;
   vector<pair<int, int>> c;
    pair<int, int > p;
    
    for(int i=0;i<n;i+=1)
    {
        cin>>temp;
        a.push_back(temp);
        if(i==0)
        {
            p = make_pair(0,0);
            c.push_back(p);
        }
        else
        {
            if(a[i-1]==1)
            {
                p = make_pair(c[i-1].first, 1);
                c.push_back(p);
            }
            else if(a[i-1]==-1)
            {
                p = make_pair(1, c[i-1].second);
                c.push_back(p);
            }
            else
            {
                p = make_pair(c[i-1].first, c[i-1].second);
                c.push_back(p);
            }
            
        }
        
    }
    for(int i=0;i<n;i+=1)
    {
        cin>>temp;
        b.push_back(temp);
    }
    bool flag = true;

    for(int i=0;i<n;i++)
    {
        if(a[i]<b[i] && c[i].second==0)
        {
            flag = false;
            break;
        }
        else if(a[i]>b[i] && c[i].first==0)
        {
            flag = false;
            break;
        }
    }

    if(flag)
    {
        cout<<"YES\n";
    }
    else
    {
        cout<<"NO\n";
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