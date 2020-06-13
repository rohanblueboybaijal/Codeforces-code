#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define ll long long int
#define F first
#define S second
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)
#define REP(i,n) for(i=0;i<(n);i+=1)

using namespace std;

//cin.ignore(numeric_limits<streamsize>::max(),'\n');

ll LOG(ll a, ll n){
    ll val = 1, x=0;
    while(val < n){
        val = val*a;
        x+=1;
    }
    if(val==n)
        return x;
    else    
        return x-1;
}

void solve() {
    int n,i;
    cin>>n;
    vector<ll> t;
    ll x, pre =0, ans=0;
    REP(i,n){
        cin>>x;
        t.PB(x);
    }
    sort(t.begin(), t.end());
    REP(i,n){
        if(pre<=t[i]){
            ans +=1;
            pre += t[i];
        }
    }
    cout<<ans<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}