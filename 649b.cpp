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
    cin>>n;
    vll p,ans;
    REP(i,0,n) {
        cin>>x;
        p.PB(x);
    }
    ans.PB(p[0]);
    REP(i,1,n-1) {
        if(p[i]>p[i-1] && p[i]>p[i+1]) ans.PB(p[i]);
        else if(p[i]<p[i-1] && p[i]<p[i+1]) ans.PB(p[i]);
    }
    ans.PB(p[n-1]);
    cout<<ans.size()<<endl;
    for(auto itr: ans) {
        cout<<itr<<" ";
    } 
    cout<<endl;
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