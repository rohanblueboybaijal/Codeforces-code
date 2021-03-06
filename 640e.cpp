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

int pre[8001];

void solve(){

    multiset<int> s;
    int x, i, n,t;
    cin>>n;
    //memset(v,0, sizeof(v));
    memset(pre,0,sizeof(pre));
    pre[0] = 0;
    REPL(i,1,n){
        cin>>x;
        //v[i-1]=x;
        s.insert(x);
        t = x + pre[i-1];
        pre[i] = t;
    }

    int j;
    int ans = 0;
    REPL(i,0,n) {
        for(j=i+2; j<=n; j+=1) {
            t = pre[j] - pre[i];
            int c = s.count(t);
            if(c){
                ans += c;
                s.erase(t);
            }
        }
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