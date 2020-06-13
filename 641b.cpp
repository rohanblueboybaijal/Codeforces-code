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
}

void solve(){
    ll n,x;
    cin>>n;
    ll maxlen = int(log2(n)) + 1;
    bool dp[maxlen+1][n+1] = {false};
    memset(dp,0, sizeof(dp));
    
    vll s;
    s.PB(0);

    ll i,j;
    REP(i,0,n) {
        cin>>x;
        s.PB(x);
    }
    ll ans = 1;
    REPL(i,1,n) {
        dp[1][i] = true;
    }

    // REPL(i,2,maxlen) {
    //     REPL(j,i,n) {
    //         REPL(x,i-1,j) {
    //             if(dp[i-1][x]) {
    //                 if(j%x==0 && s[j]>s[x]){
    //                     dp[i][j] = true;
    //                     ans = max(ans,i);
    //                 }
    //             }
    //         }
    //     }
    // }

    REPL(i,1,maxlen-1) {
        REPL(j,i,n){
            if(dp[i][j]) {
                ll k=2;
                x = j*k;
                while(x<=n) {
                    if(s[x]>s[j]){
                        dp[i+1][x] = true;
                        ans = max(ans,i+1);
                    }
                    k+=1;
                    x = j*k;
                }
            }
        }

    }

    // REPL(i,0,maxlen) {
    //     REPL(j,0,n) {
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

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