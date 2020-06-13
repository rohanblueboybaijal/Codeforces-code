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
    int n,k=-1, pos = 0;
    bool flag = true;
    cin>>n;
    int i, sum = 0;
    REP(i,0,n){
        int x;
        cin>>x;
        sum+=x;
        if(sum%2==0 && flag){
            k = i+1;
            flag = false;
        } 
        else if(x%2==0){
            pos = i+1;
        }
    }

    if(pos) cout<<"1"<<endl<<pos<<endl;
    else if(k>=1){
        cout<<k<<endl;
        REPL(i,1,k) cout<<i<<" ";
        cout<<endl;
    }
    else {
        cout<<"-1"<<endl;
    }

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