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
    ll n,k,i;
    cin>>n>>k;
    vll a;
    REP(i,0,n){
        ll x;
        cin>>x;
        a.PB(x);
    }
    vll sum(2*k + 1);
    vll mini(k+1);
    vll maxi(k+1);
    ll t, x,y;
    REP(i,0,n/2){
        t = a[i] + a[n-1-i];
        sum[t] +=1;
        x = min(a[i], a[n-i-1]);
        y = max(a[i], a[n-i-1]);
        mini[x]+=1;
        maxi[y]+=1;
    }
    REPL(i,1,k){
        mini[i] += mini[i-1];
        maxi[i] += maxi[i-1];
    }
    ll steps = 1000000000;
    ll temp;

    // REPL(i,1,k){
    //     cout<<mini[i]<<"   "<<maxi[i]<<endl;
    // }
    for(i=2; i<=2*k; i+=1){
        if(i<=k){
            temp = mini[i-1] + (mini[k]-mini[i-1])*2 - sum[i];
            steps = min(steps, temp);
        }
        else {
            temp = maxi[i-k-1]*2 + maxi[k]-maxi[i-k-1] - sum[i];
            steps = min(steps, temp);
        }
        //cout<<i<<"   "<<temp<<endl;
    }

    cout<<steps<<endl;
    
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