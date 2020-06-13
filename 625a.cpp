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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int> r,b;
    int i,x;
    REP(i,0,n) {
        cin>>x;
        r.PB(x);
    }
    REP(i,0,n){
        cin>>x;
        b.PB(x);
    }

    int rwin=0, bwin=0, ans;

    REP(i,0,n){
        if(r[i]==1 && b[i]==0) rwin+=1;
        if(r[i]==0 && b[i]==1) bwin+=1;
    }
    if(rwin==bwin && rwin ==0) ans = -1;
    else if(rwin) {
        ans = bwin/rwin;
        ans +=1;
    }
    else ans = -1;
    cout<<ans<<endl;

    return 0;
}