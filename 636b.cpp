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

void solve(){
    ll n,i;
    cin>>n;
    bool flag = true;
    if((n/2)%2==1) flag = false;
    ll m = n/2;
    vll even, odd;
    m=m/2+1;
    REPL(i,1,m){
        even.PB(8*i);
        even.PB(8*i + 4);
        odd.PB(8*i+1);
        odd.PB(8*i+3);
    }
    m=n/2;
    if(flag){
        cout<<"YES\n";
        REP(i,0,m) cout<<even[i]<<" ";
        REP(i,0,m) cout<<odd[i]<<" ";
    }
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