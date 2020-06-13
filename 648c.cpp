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
    ll n,i,x;
    multiset<int> ms;
    cin>>n;
    vll dist(n+1), a(n+1);
    REP(i,0,n) {
        cin>>x;
        a[x] = i;
    }
    REP(i,0,n) {
        cin>>x;
        int diff;
        diff = a[x]-i>=0 ? a[x]-i : n + (a[x]-i);
        ms.insert(diff);
    }
    int ans = 0;
    REPL(i,0,n) {
        int t = ms.count(i);
        ans = max(t, ans);
    } 

    cout<<ans<<endl;


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}
