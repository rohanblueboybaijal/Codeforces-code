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

struct cmp {
    bool operator() (const pair<int,int> &p1, const pair<int,int> &p2) const {
        int len1 = p1.S - p1.F + 1;
        int len2 = p2.S - p2.F + 1;
        if(len1 == len2 ) return p1.F < p2.F;
        return len1 > len2;
    }
};

void solve(){
    ll n;
    cin>>n;
    set<pair<int,int>, cmp> segs;
    pair<int, int> p;
    vector<int> a(n);
    p = MP(0,n-1);
    segs.insert(p);
    int i;
    REPL(i,1,n) {
        p = *segs.begin();
        segs.erase(segs.begin());
        int index = (p.F + p.S)/2;
        a[index] = i;
        if(p.F <  index) segs.insert({p.F, index-1});
        if(p.S > index) segs.insert({index+1, p.S});
    }
    for(auto itr : a) cout<<itr<<" ";
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