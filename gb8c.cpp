
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
    int k;
    cin>>k;
    int i,x;
    int n = 3 + (k)*2;
    int up, down;
    if(k%2) {
        up = k/2 +1;
        down = k/2 +1;
    }
    else {
        up = k/2;
        down = (k)/2 + 1;
    }
    if(k==1) {
        up=1;
        down=1;
        n = 5;
    }
    cout<<n+5*up+5*down<<endl;
    REP(i,0,n) cout<<"2 "<<i<<endl;
    for(i=0;i<2*down;i+=2) {
        cout<<"1 "<<2*i<<endl;
        cout<<"1 "<<2*i+2<<endl;
        cout<<"0 "<<2*i<<endl;
        cout<<"0 "<<2*i+1<<endl;
        cout<<"0 "<<2*i+2<<endl;
    }
    for(i=0; i<2*up; i+=2) {
        cout<<"3 "<<2*i + 2<<endl;
        cout<<"3 "<<2*i + 4<<endl;
        cout<<"4 "<<2*i + 2<<endl;
        cout<<"4 "<<2*i + 3<<endl;
        cout<<"4 "<<2*i + 4<<endl; 
    }

}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();

    return 0;
}