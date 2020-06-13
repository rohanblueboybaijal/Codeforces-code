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

vector<int> g[100001];
int val[100005];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,i,u,v;
    cin>>n;
    REP(i,1,n){
        cin>>u>>v;
        g[u].PB(i);
        g[v].PB(i);
        val[i] = -1;
    }

    pair<int,int> p(0,0),t;

    REPL(i,1,n){
        t = MP((int)g[i].size(), i);
        p = max(p,t);
    }

    int c= 0;

    for(int x : g[p.S]){
        val[x]= c;
        c+=1;
    }

    REP(i,1,n){
        if(val[i]==-1){
            val[i] = c;
            c+=1;
        }
        cout<<val[i]<<endl;
    }

    return 0;
}