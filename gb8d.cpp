
/****************************************
/ AUTHOR : ROHAN BAIJAL                  /  
/ ALIAS : rohanblueboybaijal             /
/ INSTITUTE : IIT KANPUR                 /
*****************************************/
//              TEMPLATE                //

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
    ll n;
    cin>>n;
    ll count[21], i;
    ll p[21]={0};
    REPL(i,0,20) {
        count[i] = p[i] =0;
    }
    p[0]=1;
    REPL(i,1,20) p[i] = p[i-1]*2;
    ll x;
    REP(i,0,n) {
        ll j=0, x;
        cin>>x;
        while(x) {
            count[j] += x&1;
            x=x/2;
            j++;
        }
    }
    ll y=0, sq=1, ans=0;
    while(sq) {
        y=0;
        for(i=20;i>=0;i--) {
            if(count[i]) {
                y = y + p[i];
                count[i]--;
            }
        }
        sq = y*y;
        ans += sq;
    }
    cout<<ans;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}