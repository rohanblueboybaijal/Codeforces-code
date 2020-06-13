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
    ll n,h;
    cin>>n>>h;
    ll i,x;
    vll a;
    REPL(i,1,n){
        cin>>x;
        a.PB(x);
    }

    vll v;
    int j;
    ll t=h;
    REP(i,0,n){
        v.PB(a[i]);
        sort(v.begin(),v.end(), greater<ll>());
        t = h;
        for(j=0;j<=i;j++){
            if(j%2==0){
                t = t-v[j];
            }
            if(t<=0) break;
        }
        //cout<<t<<endl;
        if(t<0){
            i--;
            break;
        }
        if(t==0 && i%2==1) break;
    }
    if(i==n) i--;
    cout<<i+1<<endl;
    return 0;

}