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
    int n,k,i;
    cin>>n>>k;
    vector<int> free;
    int table=0;
    string s;
    cin>>s;
    REP(i,0,n) {
        if(s[i]=='1') {
            int j=0;
            REPL(j,1,k) {
                if(i-j>=0) s[i-j]='2';
                if(i+j<n) s[i+j]='2';
            }
        }
    }
    REP(i,0,n) {
        if(s[i]=='0') {
            int j;
            table++;
            REPL(j,1,k) {
                if(i+j<n) s[i+j]='2';
            }
        }
    }
    cout<<table<<endl;
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