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
    int r,c;
    cin>>r>>c;
    int mat[r][c];
    int i,j;
    REP(i,0,r) mat[i][0] = i+1;
    REP(j,0,c) mat[0][j] = r+1+j;
    REP(i,1,r) {
        REP(j,0,c) {
            mat[i][j] = (i+1)*(r+1+j);
        }
    }
    if(r==1 && c!=1) REP(j,0,c) mat[0][j] = j+2;
    else if(c==1 && r!=1) REP(i,0,r) mat[i][0] = i+2;
    if(r==c && r==1) cout<<"0"<<endl;
    else {
        REP(i,0,r) {
            REP(j,0,c) {
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}