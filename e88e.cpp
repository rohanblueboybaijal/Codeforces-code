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

// ll power(ll x, ll n) {
//     ll i,ans = 1;
//     REPL(i,1,n){
//         ans = ans*x; 
//     }
//     return ans ;
// }

const int  N = 5e5 + 7;
const ll P = 998244353;
ll fac[N];

ll power(ll x, ll y, ll p) { 
    ll res = 1;
    x = x % p;
  
    while (y > 0) 
    {
        if (y & 1) 
            res = (res*x) % p; 

        y = y>>1; 
        x = (x*x) % p; 
    } 
    return res; 
} 
  
ll modInverse(ll n, ll p) { 
    return power(n, p-2, p); 
} 
  
int nCrModPFermat(ll n, ll r, ll p) 
{ 
   if (r==0) 
      return 1;
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 

void factorial(ll n, ll p=0){
    ll i;
    fac[0] =1;
    if(p) REPL(i,1,n) fac[i] = (fac[i-1]*i)%p;
    else REPL(i,1,n) fac[i] = fac[i-1]*i;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, k;
    cin>>n>>k;

    factorial(n,P);
    ll ans = 0;

    ll i, d;
    REPL(i,1,n) {
        d = n/i - 1;
        if(d>=k-1) {
            ans = (ans + nCrModPFermat(d, k-1, P))%P;
        }
    }

    cout<<ans<<endl;
    return 0;
}