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
    int c,i;
    vector<pair<int,int>> v(n+1);
    REPL(i,1,n){
        cin>>c;
        if(v[c].F==0){
            v[c].F = i;
            v[c].S = i;
        }
        else{
            v[c].S = i;
        }
    }
    sort(v.begin(), v.end());
    for(i=0;i<n+1;i++){
        if(v[i].F) break;
    }
    int j;
    int ans = 0;
    REPL(j,(i+1),n){
        int d1 = v[j].S - v[i].F ;
        int d2 = v[i].S - v[j].F;
        int d = max(d1,d2);
        ans = max(ans, d);
    }

    cout<<ans<<endl;
    return 0;
}