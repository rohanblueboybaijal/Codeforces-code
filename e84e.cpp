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

ll MOD = 998244353;
ll power[200000];

int n;

void precompute(){
    int i;
    power[0]=1;
    REPL(i,1,n){
        power[i] = ((power[i-1]%MOD)*10)%MOD;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //memset(power, 1, sizeof(power));
    cin>>n;
    precompute();
    int i;
    ll cb, mb;
    REPL(i,1,n){
        if(i==n){
            cout<<10<<" ";
        }
        else{
            cb = ((((power[n-i]%MOD)*9)%MOD)*2)%MOD;
            mb = (((((power[n-i-1]*9)%MOD)*9)%MOD)*(n-i-1))%MOD;
            cout<< (cb+mb)%MOD<<" ";
        }
    }
    cout<<endl;
    return 0;
}