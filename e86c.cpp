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

ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

ll a,b;

void solve(ll lcm){

    ll l,r, ans=0;
    cin>>l>>r;

    bool flag = true;
    if(a==1 || b==1 || a%b==0 || b%a==0) flag = false;

    ll block = lcm - max(a,b); 
    //cout<<block<<endl;
    ll blocks = r/lcm;
    ll nl = lcm*blocks;


    ll x, count = 0;
    x = r - nl;
    count = x-max(a,b) + 1;
    if(count >=0) ans += count;
    // for(x = nl+1 ;x<=r; x++){
    //     if((x%a)%b != (x%b)%a) count +=1;
    // }
    ans +=  blocks*block;

    blocks = l/lcm;
    nl = lcm*blocks;
    x = l - nl;
    count = x - max(a,b) + 1;
    if(count>=0) ans = ans - count;

    // for(x = nl+1 ;x<=l; x++){
    //     if((x%a)%b != (x%b)%a) count +=1;
    // }
    ans = ans - blocks*block;

    if((l%a)%b != (l%b)%a) ans +=1;

    if(!flag) ans = 0;

    cout<<ans<<" ";
}

void counting(){
    int q;
    cin>>a>>b>>q;
    ll g = gcd(a,b);
    ll lcm = (a*b)/g;
    while(q--){
        solve(lcm);
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        counting();
        cout<<endl;
    }
    return 0;
}