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

const int INF = 1e9;

int func(int x, int l, int r){
    if(x>=l && x<=r) return 1;
    return 0;
}

//dp[i][j] is the maximum number of good sleeping times if Vova had a sleep i times already 
// and the number of times he goes to sleep early is j

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,h,l,r;
    cin>>n>>h>>l>>r;
    vector<int> a;
    vector<int> pre;
    pre.PB(0);
    int i,x,j;
    REPL(i,1,n){
        cin>>x;
        a.PB(x);
        pre.PB(x + pre[i-1]);
    }
    vector<vector<int>> dp(n+1);
    REP(i,0,n+1){
        REP(j,0,n+1){
            dp[i].PB(0);
        }
    }

    REPL(i,1,n){
        REPL(j,0,i){
            if(j==0){
                dp[i][j] = dp[i-1][j] + func(pre[i]%h, l, r);
            }
            else{
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-1]) + func((pre[i]-j)%h, l,r);
            }
        }
    }
    int ans = 0;
    REPL(i,0,n){
        ans = max(ans, dp[n][i]);
    }
    cout<<ans<<endl;
    return 0;
}