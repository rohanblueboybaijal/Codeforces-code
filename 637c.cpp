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
    int n;
    cin>>n;
    vector<pair<ll,ll>> perm;
    pair<ll,ll> p;
    ll x,i;
    REP(i,0,n){
        cin>>x;
        p = MP(x,i+1);
        perm.PB(p);
    }
    sort(perm.begin(), perm.end() );
    bool flag = true;
    vector<bool> pos(n+1);
    REPL(i,1,n){
        pos[i] = false;
    }
    ll last = perm[0].S;
    ll id;
    pos[perm[0].S]= true;
    REP(i,1,n){
        id = perm[i-1].S;
        if(id!=n){
            if(pos[id+1]==false){
                if(perm[i].S!=id+1) {
                    flag = false;
                }
                pos[id+1] = true;
            }
        }
        pos[perm[i].S]= true;
    }
    if(flag)cout<<"Yes";
    else cout<<"No";
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