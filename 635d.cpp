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

ll compute(ll x, ll y, ll z) {
    ll val ;
    val = (x-y)*(x-y) + (y-z)*(y-z) + (z-x)*(z-x);
    return val;
}



void solve(){
    int nr,ng,nb;
    cin>>nr>>ng>>nb;
    vll r,g,b;
    int i;
    ll x;
    REP(i,0,nr){
        cin>>x;
        r.PB(x);
    }
    REP(i,0,ng){
        cin>>x;
        g.PB(x);
    }
    REP(i,0,nb){
        cin>>x;
        b.PB(x);
    }

    

    sort(r.begin(), r.end());
    sort(g.begin(), g.end());
    sort(b.begin(), b.end());

    r.PB(-1000000000);
    g.PB(-1000000000);
    b.PB(-1000000000);


    ll ans = 9e18;

    ans = min(ans, compute(r[0],g[0], b[0]));
    ll tr, tg, tb, temp;
    int j,k;

    i=j=k=0;
    while(i<nr && j<ng && k<nb){

        tr = compute(r[i+1], g[j], b[k]);
        tg = compute(r[i], g[j+1], b[k]);
        tb = compute(r[i], g[j], b[k+1]); 
        temp = min(tr, min(tg, tb));
        if (temp == tr) i+=1;
        else if (temp == tg) j +=1;
        else if(temp==tb)k+=1;

        ans = min(ans, temp);
        if(ans==0){
            break;
        }

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