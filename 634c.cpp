#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define ll long long int
#define F first
#define S second
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)
#define REP(i,n) for(i=0;i<(n);i+=1)

typedef vector<ll> vll;
typedef set<int>::iterator sit;
typedef unordered_set<int>::iterator usit;
typedef multiset<int>::iterator msit;
typedef unordered_multiset<int>::iterator umsit;
typedef vector<ll>::iterator vllit;

//cin.ignore(numeric_limits<streamsize>::max(),'\n');

ll LOG(ll a, ll n){
    ll val = 1, x=0;
    while(val < n){
        val = val*a;
        x+=1;
    }
    if(val==n)
        return x;
    else    
        return x-1;
}

void solve() {
    int n,i,x;
    int rep =0, maxrep=1, distinct = 0, count =0;
    int ans = 0;
    multiset<int> ms;
    set<int> s;

    cin>>n;
    REP(i,n){
        cin>>x;
        ms.insert(x);
        s.insert(x);
    }
    distinct = s.size();
    sit itr= s.begin();
    for(itr ; itr!= s.end(); itr++){
        count = ms.count(*itr);
        maxrep = MAX(maxrep, count);
        if(count>1)
            rep +=1;
    }
    if(distinct == maxrep){
        ans = distinct -1 ;
    }
    else {
        ans = MIN(distinct , maxrep);
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