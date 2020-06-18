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
    ll n, x, i;
    cin>>n>>x;
    vll a;
    ll sum=0;
    bool div[n+1];
    bool flag = false;
    ll first = 0;
    ll last=0;
    REPL(i,1,n) {
        ll y;
        cin>>y;
        if(y%x) {
            if(first==0) first = i;
            last = i;
        }
        sum+=y;
    }
    ll ans = -1;
    //cout<<first<<" "<<last<<endl;
    if(sum%x==0) {
        if(first) {
            ll t1, t2;
            if(first==last) {
                t1=n-first+1;
                t2 =last;
                ans = max(t1,t2);
            }
            else {
                t1 = max(first, n-first);
                t2 = max(last-1, n-last+1);
                ans = max(t1,t2);
            }
        }
        else ans =-1;
    }
    else {
        ans = n;
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