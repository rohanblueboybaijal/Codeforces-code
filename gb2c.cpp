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
    int n,m;
    cin>>n>>m;
    int a[n][m], b[n][m];
    int suma=0;
    int sumb=0;
    int i,j;
    REP(i,0,n){
        REP(j,0,m){
            cin>>a[i][j];
            if(a[i][j]) suma+=1;
        }
    }
    int inc=0;
    int dec=0;
    REP(i,0,n){
        REP(j,0,m){
            cin>>b[i][j];
            if(b[i][j]) sumb +=1;
        }
    }
    int cola[m], rowa[n];
    int colb[m], rowb[n];
    REP(i,0,n){
        rowa[i]=0;
        rowb[i]=0;
        REP(j,0,m){
            rowa[i] += a[i][j];
            rowb[i] += b[i][j];
        }
    }
    REP(j,0,m){
        cola[j]=0;
        colb[j]=0;
        REP(i,0,n){
            cola[j] += a[i][j];
            colb[j] += b[i][j];
        }
    }
    // REP(i,0,n){
    //     cout<<rowa[i]<<" "<<rowb[i]<<endl;      
    // }
    // REP(j,0,m){
    //     cout<<cola[j]<<" ";
    // }
    // cout<<endl;
    // REP(j,0,m){
    //     cout<<colb[j]<<" ";
    // }
    // cout<<endl;

    bool flag = true;
    if(suma%2 != sumb%2) flag = false;
    REP(i,0,n){
        if(rowa[i]%2 != rowb[i]%2) flag =false;
    }
    REP(i,0,m){
        if(cola[i]%2 != colb[i]%2) flag = false;
    }
    if(flag) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}