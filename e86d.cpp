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
    
    int n, k;
    cin>>n>>k;
    vector<int> vi(k+1), pre(k+1), c(k+1), arr;
    vi[0] = 0;
    pre[0] = 0;
    c[0] = 0;
    int i, ans = 0;
    REP(i,0,n){
        int x;
        cin>>x;
        arr.PB(x);
        vi[x] +=1;
    }
    REPL(i,1,k){
        int x;
        cin>>x;
        c[i] = x;
        pre[i] = pre[i-1] + vi[i];
        int req = (n-pre[i-1])/c[i];
        if((n-pre[i-1])%c[i] != 0) {
            req+=1;
        }
        ans = max(req,ans);
    }

    sort(arr.begin(), arr.end());

    cout<<ans<<endl;

    return 0;
}