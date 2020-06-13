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
    int n,m,k;
    cin>>n>>m>>k;
    int i,j,x,y;
    REP(i,0,k){
        cin>>x>>y;
    }
    REP(i,0,k){
        cin>>x>>y;
    }

    ll steps = 0;
    steps = m-1 + n-1 + n*m-1;
    cout<<steps<<endl;
    REPL(i,1,m-1){
        cout<<"L";
    }
    REPL(i,1,n-1){
        cout<<"U";
    }
    REPL(i,1,n){
        REPL(j,1,m-1){
            if(i%2)
                cout<<"R";
            else 
                cout<<"L";
        }
        if(i<n)
            cout<<"D";
    }
    cout<<endl;
    return 0;
}