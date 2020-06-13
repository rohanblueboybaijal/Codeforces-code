#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define ll long long int
#define F first
#define S second
#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)

//cin.ignore(numeric_limits<streamsize>::max(),'\n');

using namespace std;

void func(){
    vector <ll> a, r;
    int n,i;
    cin>>n;
    ll x,y;
    for(i=0;i<n;i+=1){
        cin>>x;
        a.pb(x);
    }
    sort(a.begin(), a.end());
    r = a;
    reverse(r.begin(), r.end());
    if(n%2==0) {
        i=n/2;
        for(i;i<n;i+=1){
            cout<<a[i]<<" "<<r[i]<<" ";
        }
    }
    else
    {
        i=n/2;
        cout<<a[i]<<" ";
        i+=1;
        for(i;i<n;i+=1){
            cout<<r[i]<<" "<<a[i]<<" ";
        }
    }
    cout<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        func();
    return 0;
}