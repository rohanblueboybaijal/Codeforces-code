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
    ll n,x,i;
    bool sign = true;
    ll sum=0;
    ll pos=0;
    ll neg =-1000000000;
    cin>>n;
    vll a;


    cin>>x;
    if(x<0) sign= false;
    a.PB(x);
    if(sign) pos = x;
    else neg = x;

    REP(i,0,n-1){
        cin>>x;
        if(x>0 && sign){
            pos = max(pos, x);
        }
        else if(x>0 && !sign){
            sum = sum + neg;
            pos = x;
            sign = true;
        }
        else if(x<0 && !sign){
            neg = max(neg,x);
        }
        else if(x<0 && sign){
            sum = sum + pos;
            pos =0;
            neg = x;
            sign = false;
        }
    }
    if(sign) sum +=pos;
    else sum+=neg;
    cout<<sum<<endl;

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