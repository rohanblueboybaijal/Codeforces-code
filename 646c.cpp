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

// vector<int> adj[1005];
// int cnt[1005];

// void subtreeCount(int s, int e) {
//     vector<int>::iterator itr;
//     cnt[s]=1;
//     for(itr=adj[s].begin(); itr!=adj[s].end(); itr++) {

//         if(*itr==e) continue;
//         subtreeCount(*itr,s);
//         cnt[s]+=cnt[*itr];
//     }
// }

void solve() {

    int n,x;
    cin>>n>>x;
    int i,u,v;
    string ans;
    int deg = 0;
    REP(i,0,n-1) {
        cin>>u>>v;
        if(u==x || v==x) deg+=1;
    }
    if(deg<=1) ans = "Ayush";
    else {
        int t = n-3;
        if(t%2) ans = "Ayush";
        else ans = "Ashish";
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