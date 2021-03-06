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
    int n,i;
    cin>>n;
    multiset<int> store;
    vector<int > a;
    bool flag = false;
    int x,y;
    cin>>x;
    store.insert(x);
    REP(i,0,n-1){
        cin>>y;
        store.insert(y);
        if(store.count(y)>2)
            flag = true;
        else if(store.count(y)==2 && y!=x)
            flag = true;
        x=y;
    }
    if(flag)
        cout<<"YES\n";
    else 
        cout<<"NO\n";

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