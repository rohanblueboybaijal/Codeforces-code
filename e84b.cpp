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
    int n;
    cin>>n;

    bool d[n];
    memset(d,0, sizeof(d));
    bitset<100001> s;

    int i,j,x,k,pos=-1;

    REP(i,0,n){
        cin>>k;
        REP(j,0,k){
            cin>>x;
            if(!s[x] && !d[i]){
                d[i]= true;
                s[x]=1;
            }
        }
        if(!d[i]){
            pos = i;
        }
    }

    int ans =0;

    REPL(i,1,n){
        if(!s[i]){
            ans = i;   
            break;
        }
    }

    if(pos !=-1){
        cout<<"IMPROVE\n";
        cout<<pos+1<<" "<<ans;
    }
    else 
        cout<<"OPTIMAL";
    cout<<endl;
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