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

void solve() {
    string s;
    cin>>s;
    int m, i;
    cin>>m;
    vector<char> t(m);
    vector<pair<int, int>> vp;
    int alpha[26] = {0};
    bool visited[m];
    memset(visited, false, sizeof(visited));
    REP(i,0,m) {
        int x;
        cin>>x;
        vp.PB({x,i});
    }
    REP(i,0,(int)s.length()) {
        alpha[s[i]-97] ++;
    }
    sort(vp.begin(), vp.end());
    int top = 25;
    REP(i,0,m) {
        int size = vp.size();
        if(!size) break;
        int count =0;
        int j=0;
        REP(j,0,size) {
            if(vp[j].F==0) count++;
            else break;
        }
        
        while(alpha[top]<count) top--;
        REP(j,count, size) {
            int x=0;
            REP(x,0,count) vp[j].F = vp[j].F - abs(vp[j].S - vp[x].S);
        }

        REP(j,0,count) {
            t[vp[j].S] = (char)(top+97);
        }
        REP(j,0,count) {
            vp.erase(vp.begin());
        }
        top--;
        sort(vp.begin(), vp.end());
    }
    REP(i,0,m) cout<<t[i];
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