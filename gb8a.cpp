
/****************************************
/ AUTHOR : ROHAN BAIJAL                  /  
/ ALIAS : rohanblueboybaijal             /
/ INSTITUTE : IIT KANPUR                 /
*****************************************/
//              TEMPLATE                //

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

void solve() {
    ll a,b,n;
    cin>>a>>b>>n;
    ll ta=a, tb=b, s1, s2;
    ll cnt =0;
    while(ta<=n && tb<=n) {
        ta = a + b;
        tb = b;
        s1 = ta + tb;
        ta = a;
        tb = a + b;
        s2 = ta + tb;
        if(s1>s2) {
            a= a + b;
            b= b;
        }
        else {
            a = a;
            b = a+b;
        }
        cnt ++;
    }
    cout<<cnt<<endl;
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