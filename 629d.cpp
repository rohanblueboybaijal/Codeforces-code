#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define MP make_pair
#define PB push_back
#define F first
#define S second
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)
#define REP(i,n) for(i=0;i<(n);i+=1)
#define REP1(i,n) for(i=1;i<(n);i+=1)

typedef vector<ll> vll;
typedef set<int>::iterator sit;
typedef unordered_set<int>::iterator usit;
typedef multiset<int>::iterator msit;
typedef unordered_multiset<int>::iterator umsit;
typedef vector<ll>::iterator vllit;

//cin.ignore(numeric_limits<streamsize>::max(),'\n');

ll LOG(ll a, ll n){
    ll val = 1, x=0;
    while(val < n){
        val = val*a;
        x+=1;
    }
    if(val==n)
        return x;
    else    
        return x-1;
}

void solve(){
    int n,x,i;
    int c=1, col=1, pos = -1;
    cin>>n;
    vll t;
    cin>>x;
    t.PB(x);
    REP1(i,n){
        cin>>x;
        t.PB(x);
        if(x!=t[i-1])
            c+=1;
        else 
            pos = i-1;
    }
    if(t[0]==t[n-1]){
        c=c-1;
        pos =  n-1;
    }
    
    if(c==0){
        cout<<"1\n";
        REP(i,n)
            cout<<"1 ";
    }
    else if(n%2==0){
        cout<<"2\n";
        REP(i,n){
            cout<<i%2+1<<" ";
        }
    }
    else if(c<n){
        cout<<"2\n";
        REP(i,n){
            if(i==(pos+1)%n){
                cout<<col<<" ";
            }
            else {
                col = col==1 ? 2:1;
                cout<<col<<" ";
            }
        }

    }
    else {
        cout<<"3\n";
        REP1(i,n){
            cout<<i%2 + 1<<" ";
        }
        cout<<"3 ";
    }
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