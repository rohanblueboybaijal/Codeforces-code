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
    string t;
    getline(cin,t);
    int len = t.length();
    bool flag = true;
    int i;
    REP(i,0,len-1){
        if(t[i]!=t[i+1]) flag = false;
    }
    char first='1', sec='0';
    string s;
    if(!flag){
        if(t[0]=='0'){
            first ='0';
            sec = '1';
        }
        REP(i,0,len){
            s.PB(first);
            s.PB(sec);
        }
    }
    else {
        s= t;
    }
    cout<<s<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    while(t--){
        solve();
    }

    return 0;
}