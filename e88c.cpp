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

ll power(ll x, ll n) {
    ll i,ans = 1;
    REPL(i,1,n){
        ans = ans*x; 
    }
    return ans ;
}

void solve() {
    ll h,c,tb;
    cin>>h>>c>>tb;
    ll ans = 1;
    bool find = true;
    if(h==tb){
        ans = 1;
        find = false;
    }
    else if(h+c>=2*tb) {
        find = false;
        ans =2;
    }
    ll x, a, b;
    a = h-tb;
    b = 2*tb - h - c;
    ll diff = h-tb;
    ll temp;
    if(find) {
        x = a/b;
        ll val1 = abs((2*x+1)*tb - (h+c)*x - h);
        ll val2 = abs((2*x+3)*tb - (h+c)*(x+1) -h);
        ans = (2*x + 3)*val1 <= (2*x+1)*val2 ? 2*x + 1 : 2*x + 3; 
    }
    cout<<ans<<endl;
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