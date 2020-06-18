
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
    ll k,i;
    cin>>k;
    ll a[10];
    REP(i,0,10) a[i]=1;
    string s = "codeforces";
    ll prod = 1;
    REPL(i,2,40) {
        ll j;
        prod=1;
        REP(j,0,10) prod = prod*(i-1);
        REP(j,0,10) {
            a[j] = i;
            prod = prod/(i-1);
            prod = prod*i;
            if(prod>=k) break;
        }
        if(prod>=k) break;
    }
    string ans;
    REP(i,0,10) {
        string s1;
        ll j;
        REP(j,0,a[i]) {
            s1 += s[i];
        }
        ans += s1;
    }
    if(k==1) ans = s;
        
    cout<<ans<<endl;


}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}