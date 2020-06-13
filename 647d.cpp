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

const int N = 5e5  + 5;
vector<int> adj[N];
int topic[N];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int i, a, b;
    REP(i,0,m) {
        cin>>a>>b;
        adj[a].PB(b);
        adj[b].PB(a);
    }
    bool flag = true;
    vector<pair<int,int>> vp;
    REPL(i,1,n) {
        cin>>a;
        topic[i] = a;
        pair<int, int> p = MP(a, i);
        vp.PB(p);
    }
    sort(vp.begin(), vp.end());

    REP(i,0,n) {
        a = vp[i].S;
        int t = vp[i].F;

        bool f1, f2;
        f1=true;
        f2 = t==1 ? true : false;
        for(auto& itr : adj[a]) {
            if(topic[itr]==t) f1=false;
            if(topic[itr]==t-1) f2=true;
        }

        if(!f1 || !f2) {
            flag = false;
            break;
        }
    }

    if(flag) {
        REP(i,0,n) cout<<vp[i].S<<" ";
    }
    else cout<<-1;
    cout<<endl;
    return 0;
}