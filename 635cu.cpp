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

bool cmpGreater(int a, int b){
    return a>b;
}

const int N = 2e5 + 7;
const int INF = 1e9;;
vector<int> G[N];
int n,k;
int depth[N]={0};
int siz[N]={0};
vector<int> det(N, -INF);

void dfs(int c, int p){
    depth[c] =  depth[p] + 1;
    siz[c] = 1;
    int i;
    vector<int>::iterator u;
    for(u=G[c].begin(); u!=G[c].end();u++){
        
        //condition to omit reverse path
        if(*u == p)
            continue;
        dfs(*u,c);
        siz[c] += siz[*u];
    }
    det[c] = siz[c] - depth[c];

}

//size of subtree counts the root too. That's why we have (size -1)
//depth of 1 (ROOT) is 1. That's why we have (depth -1) 

// For every node we calulate the max happiness it could provide i it were chosen as a tourism industry
// So we just need to consider each node separately and finally sort the values in descending order
// Choose first n-k values as we need k industries. The last k values make the least contribution as a toursim industry

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>k;
    int i;
    int u,v;
    REP(i,1,n){
        cin>>u>>v;
        G[u].PB(v);
        G[v].PB(u);
    }

    dfs(1,0);
    sort(det.begin(), det.end(), cmpGreater);
    // REPL(i,1,n){
    //      cout<<i<<"   "<<depth[i]<<" "<<siz[i]<<" "<<det[i]<<endl;
    // }

    ll ans =0;
    for(i=0;i<n-k;i+=1)
        ans +=det[i];
    printf("%lld\n", ans);
    return 0;
}