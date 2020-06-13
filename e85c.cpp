#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define ll long long int
#define F first
#define S second
#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) (x)<(y)?(x):(y)

using namespace std;

void func(){
    int n,i;
    cin>>n;
    vector <pair<ll, ll>> v;
    pair <ll,ll> p;
    ll pre = 0;
    ll bul = LLONG_MAX;
    ll a,b;
    ll ans = LLONG_MAX;
    ll x,y;
    cin>>a>>b;
    p = mp(a,b);
    v.pb(p);
    for(i=1;i<n;i+=1){
        cin>>a>>b;
        p = mp(a,b);
        v.pb(p);
        x = max(0,(v[i].F - v[i-1].S));
        pre +=x;
        bul = min(bul, v[i].F - x);
    }
    x = max(0, (v[0].F - v[n-1].S));
    pre +=x;
    bul = min(bul, v[0].F - x);
    ans = pre + bul;
    cout<<ans<<endl;
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