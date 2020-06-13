#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MP make_pair
#define PB push_back
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
    int n,k;
    ll i, x;
    cin>>n>>k;
    string s(n,'a');
    for(i=1;i<n;i+=1){
        x = (i*(i+1))/2;
        if(x>=k)
            break;
    }
    s[n-1 -i] = 'b';
    if(x!=k){
        x = (i*(i-1))/2;
        i = k-x;
        s[n - i] ='b';
    }
    else 
        s[n-1-i+1]='b';
    cout<<s<<endl;
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