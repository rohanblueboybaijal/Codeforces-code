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
    int n,k;
    cin>>n>>k;
    vector<int> a, b;
    set<int> s;
    sit itr;
    bool flag = true;
    int x,i;
    REP(i,0,n){
        cin>>x;
        a.PB(x);
        s.insert(x);
    }
    if(s.size()>k) flag = false;

    if(flag && s.size()>1){
        int distinct = s.size();
        for(itr=s.begin(); itr!=s.end(); itr++){
            x = *itr;
            b.PB(x);
        }

        int extra = k - distinct;

        for(i=1;i<=n && extra>0;i++){
            if(s.count(i)==0){
                b.PB(i);
                extra --;
            }
        }

        int rep = n-1;
        REP(i,0,rep) {
            int j;
            REP(j,0,k) {
                b.PB(b[j]);
                //cout<<b[j]<<" ";
            }
        }
        cout<<b.size()<<endl;
        for(i=0;i<b.size();i++){
            cout<<b[i]<<" ";
        }
    }
    else if(flag) {
        cout<<n<<endl;
        REP(i,0,n){
            cout<<a[i]<<" ";
        }
    }
    else cout<<"-1";

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