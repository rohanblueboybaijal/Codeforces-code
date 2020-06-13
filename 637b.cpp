#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define ll long long int
#define F first
#define S second
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)
#define REP(i,a,n) for(i=a;i<(n);i+=1)
#define REPL(i,a,n) for(i=a;i<=(n); i+=1)
#define REPr(i,n) for(i=n-1;i>=0;i-=1)

typedef vector<ll> vll;
typedef set<int>::iterator sit;
typedef unordered_set<int>::iterator usit;
typedef multiset<int>::iterator msit;
typedef unordered_multiset<int>::iterator umsit;
typedef vector<ll>::iterator vllit;

//cin.ignore(numeric_limits<streamsize>::max(),'\n');

ll MAX3(ll x , ll y, ll z){
    ll t = max(x,y);
    return max(t,z);
}

void solve(){
    ll n,k;
    ll i,x;
    vll a;
    cin>>n>>k;
    REP(i,0,n){
        cin>>x;
        a.PB(x);
    }

    ll p,l, temp;
    vll pre;
    vll ispeak;
    pre.PB(0);
    ispeak.PB(0);
    REPL(i,1,n-2){
        if(a[i]>a[i-1] && a[i]>a[i+1]){
            temp = pre[i-1] + 1;
            pre.PB(temp);
            ispeak.PB(1);
        }
        else {
            temp = pre[i-1];
            pre.PB(temp);
            ispeak.PB(0);
        }
    }
    temp = pre[n-2];
    pre.PB(temp);
    ispeak.PB(0);
    ll peaks = 0;
    ll ans = 0;

    // REP(i,0,n){
    //     cout<<pre[i]<<" ";
    // }
    // cout<<endl;
    // REP(i,0,n){
    //     cout<<ispeak[i]<<" ";
    // }
    // cout<<endl;

    REP(i,0,(n-k+1)){
        peaks = pre[i+k-1] - pre[i] - ispeak[i+k-1];
        if(peaks>ans){
            ans = peaks;
            l = i;
        }
    }
    if(ans==0){
        ans = 1;
        l = 1;
    }
    else {
        ans = ans + 1;
        l = l+1;
    }
    cout<<ans<<" "<<l<<endl;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}