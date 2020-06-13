#include <bits/stdc++.h>
using namespace std;

void func() {
    int n;
    cin>>n;
    vector<int> p,c;
    int x,y,i;
    for(i=0;i<n;i+=1) {
        cin>>x>>y;
        p.push_back(x);
        c.push_back(y);
    }
    bool flag = true;
    if(c[0]>p[0])
        flag =false;
    for(i=1;(i<n)&&flag;i+=1){
        if(p[i]<p[i-1])
            flag = false;
        if(c[i]<c[i-1])
            flag = false;
        if(c[i]>p[i])
            flag = false;
        if((p[i]==p[i-1]) && (c[i]!=c[i-1]))
            flag = false;
        if(c[i]-c[i-1]>p[i]-p[i-1])
            flag = false;
    }
    if(flag)
        cout<<"YES"<<endl;
    else 
        cout<<"NO"<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--)
        func();
    return 0;
}