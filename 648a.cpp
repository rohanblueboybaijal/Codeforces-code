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
    int n,m;
    cin>>n>>m;
    int mat[n][m];
    int rows[n], cols[m];
    int i,j;
    REP(i,0,n) rows[i]=1;
    REP(i,0,m) cols[i]=1;
    REP(i,0,n) {
        REP(j,0,m){
            int x;
            cin>>x;
            if(x) {
                rows[i]=0;
                cols[j]=0;
            }
        }
    }
    int r=0, c=0;
    REP(i,0,n) r+=rows[i];
    REP(i,0,m) c+=cols[i];
    int x = min(r,c);
    if(x%2) cout<<"Ashish"<<endl;
    else cout<<"Vivek"<<endl;
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
