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
    int n, i,x,j;
    cin>>n;

    vector<vector<int>> pre(201, vector<int>(n + 1));
    vector<vector<int>> pos(201);
    int ans = 0;
    REPL(i,1,n){
        cin>>x;
        pos[x].PB(i-1);
        REPL(j,1,200){
            pre[j][i] = pre[j][i-1];
        }
        pre[x][i] += 1;
    }

    int l,r, p;
    int cntout=0;
    int cntin = 0;

    REPL(i,1,200){
        ans = max(ans , (int)(pos[i].size()));
        REP(p, 0, ((int)(pos[i].size()))/2){
            l = pos[i][p] + 1;
            r = pos[i][(int)(pos[i].size()) - p -1] - 1;
            REPL(j,1,200){
                int sum = pre[j][r+1] - pre[j][l];
                ans = max(ans, (p+1)*2 + sum);
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