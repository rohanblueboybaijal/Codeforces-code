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
    int n,i;
    cin>>n;
    vector<int> a, ans(n);
    bool done[1000007];
    memset(done, false, sizeof(done));
    int x;
    REP(i,0,n) {
        cin>>x;
        a.PB(x);
        done[x] = true;
        ans[i] = -1;
    }
    vector<int> left;
    REPL(i,0,1000007) {
        if(!done[i]) left.PB(i);
    }
    REP(i,1,n) {
        if(a[i]!=a[i-1]) ans[i] = a[i-1];
    }
    int k = 0;
    REP(i,0,n) {
        ans[i]==-1 ? ans[i] = left[k++] : ans[i] = ans[i];
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}