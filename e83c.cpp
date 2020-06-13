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
    ll n,x,i,j,k;
    cin>>n>>k;
    vector<int> a;
    set<int> s;
    bool flag = true;
    bitset<50> mask;
    REP(i,0,n){
        cin>>x;
        a.PB(x);
        if(s.count(x)>0 && x!=0) flag = false; 
        else {
            j=0;
            while(x>0){
                ll rem = x%k;
                if(rem > 1) flag = false;
                else {
                    if(mask[j]==0 && rem==1) mask[j]=1;
                    else if(mask[j]==1 && rem==1) {
                        flag = false;
                    }
                    j+=1;
                }
                x = x/k;
            }
        }
    }
    if(flag) cout<<"YES";
    else cout<<"NO";
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