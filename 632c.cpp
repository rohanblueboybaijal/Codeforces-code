#include <bits/stdc++.h>
using namespace std;

typedef unordered_multiset<long long int>::iterator umit;
typedef unordered_set<long long int>::iterator usit;

long long int binom(long long int n, long long int r)
{
    long long int ans =1;
    for(long long int i=0 ; i<n;i+=1)
    {
        if(i<r)
        {
            ans = (ans*(n-i))/(i+1);
        }
        else
        {
            ans = (ans*(n-i))/(n-i);
        }    
    }
    return ans ;
}

int main()
{
    int n;
    cin>>n;
    vector<int> a;
    int temp;
    vector<long long> s;
    unordered_multiset<long long int> um;
    unordered_set<long long int> us;
    long long int ans = (n*(n+1))/2;
    int i;
    for(i=0;i<n;i+=1)
    {
        cin>>temp;
        a.push_back(temp);
        if(i==0)
            s.push_back(temp);
        else 
            s.push_back(s[i-1] + temp);

        um.insert(s[i]);
        us.insert(s[i]);
    }
    usit it = us.begin();
    long long int val=0;
    for(; it!=us.end();it++)
    {
        val = um.count(*it);
        if(*it==0)
        {
            val = (val*(val-1))/2;
            ans = ans - um.count(*it) - val;
        }
        else if(val>=2)
        {
            ans = ans - ((val)*(val-1))/2;
        }
    }
    if(a[0]==a[n-1])
        ans=ans-1;
    cout<<ans<<endl;
    return 0;

}