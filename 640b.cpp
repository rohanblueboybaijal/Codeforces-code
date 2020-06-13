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
    ll n,k;
    cin>>n>>k;
    bool flag = true;
    ll i;
    if(k>n) flag = false;
    if(flag) {
        if(n%k==0) {
            ll t = n/k;
            cout<<"YES"<<endl;
            REP(i,0,k){
                cout<<t<<" ";
            }
            cout<<endl;
        }
        else if (n%2==1 && k%2==0) {
            flag = false;
        }
        else if (n%2==1 && k%2 ==1) {
            cout<<"YES"<<endl;
            REPL(i,1,k-1) {
                cout<<"1 ";
            }
            cout<<n-(k-1)<<endl;
        }
        else if (n%2==0 && k%2==0) {
            // if(n<2*k) flag = false;
            // else {
            //     cout<<"YES"<<endl;
            //     REPL(i,1,k-1) {
            //         cout<<"2 ";
            //     }
            //     cout<<n - 2*(k-1)<<endl;
            // }
            cout<<"YES"<<endl;
            REPL(i,1,k-1) {
                cout<<"1 ";
            }
            cout<<n-(k-1)<<endl;
        }
        else if (n%2==0 && k%2==1) {
            if (n<2*k) {
                flag = false;
            }
            else {
                cout<<"YES"<<endl;
                REPL(i,1,k-1) {
                    cout<<"2 ";
                }
                cout<<n - 2*(k-1)<<endl;
            }
        }
    }
    if(!flag) {
        cout<<"NO"<<endl;
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