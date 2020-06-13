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

struct info {
    int id;
    int d;
    //int p;
    int size;
};

const int N = 2e5 + 7;

void solve(){
    int n, i,x,j;
    cin>>n;

    vector<vector<int>> pre(27, vector<int>(n + 1));
    int ans = 0;
    REPL(i,1,n){
        cin>>x;
        REPL(j,1,26){
            pre[j][i] = pre[j][i-1];
        }
        pre[x][i] += 1;
    }
    REPL(i,1,26){
        ans = max(ans , pre[i][n]);
    }

    int l,r;
    int cntout=0;
    int cntin = 0;

    /*REPL(l,1,26){
        REPL(i,0,n){
            cout<<pre[l][i]<<" ";
        }
        cout<<endl;
    }*/

    REP(l,0,n){
        REP(r,l,n){
            cntin = cntout =0;
            REPL(i,1,26){
                cntin = max(pre[i][r+1]-pre[i][l], cntin);
                int t = min(pre[i][l], pre[i][n]-pre[i][r+1]);
                cntout = max(cntout, 2*t);
                ans = max(ans, cntout + cntin);
            }
        }
    }

    cout<<ans<<endl;
}

/*The array is zero based. SO pre is of length (n+1). pre[el][x] means the number of occurences of el upto index x-1 in the array (array is 0 indexed). 
So, if I want all the occurences of an element upto index x in the array, i would need pre[el][x+1].
For sum(c,l,r) -> number of occurences of element c from index l to index r is pre[c][r+1] - pre[c][l]*/



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