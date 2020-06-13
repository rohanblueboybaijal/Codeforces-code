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

void solve(){
    int n;
    cin>>n;
    int arr[n];
    int i;
    REP(i,0,n) {
        int x;
        cin>>x;
        arr[i] = x;
    }
    int preva = 0, prevb = 0;
    int a = 0,b=0;

    int j = n-1;
    i = 0;
    int chance = 0;
    while(j>=i) {
        if(chance % 2== 0) {
            preva = 0;
            while(preva<=prevb && j>=i) {
                preva += arr[i];
                i+=1;
            }
            a += preva;
            chance+=1;
        }
        else {
            prevb=0;
            while(prevb <= preva && j>=i){
                prevb += arr[j];
                j--;
            }
            b += prevb;
            chance +=1;
        }
    }
    cout<<chance<<" "<<a<<" "<<b<<endl;

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