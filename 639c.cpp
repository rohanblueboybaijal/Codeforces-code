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

void solve(){
    vll a;
    ll x;
    int n,i;
    set<int> s;
    cin>>n;
    REP(i,0,n) {
        cin>>x;
        a.PB(x);
    }
    int r = 0;
    bool flag = true;
    REP(i,0,n) {
        ll t = a[i] + i;
        if(t >= 0) {
            r = t%n;
        }
        else {
            r = (n - abs(t)%n)%n;
        }
        if(s.count(r)==1){
            flag = false;
            break;
        }
        else{
            s.insert(r);
        }
        //cout<<r<<endl;
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
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