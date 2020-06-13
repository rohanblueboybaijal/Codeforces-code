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

int T;
vector<int> parent, depth;
vector<int> tin, tout;
vector<vector<int>> g;

void dfs(int v, int par, int dep){
    parent[v] = par;
    depth[v] = dep;
    tin[v] = T++;
    for(auto child : g[v]){
        if(child == par) continue;
        dfs(child, v, dep+1);        
    }
    tout[v] = T++;
}

bool isAncestor(int v, int u){
    return (tin[v]<=tin[u] && tout[v]>=tout[u]);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,i;
    cin>>n>>m;
    g = vector<vector<int>>(n+1);
    parent = vector<int>(n+1);
    depth = vector<int>(n+1);
    tin = vector<int>(n+1);
    tout = vector<int>(n+1);
    T=0;
    int u,v;
    REP(i,1,n){
        cin>>u>>v;
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,-1,0);

    // REPL(i,1,n){
    //     cout<<i<<" "<<parent[i]<<" "<<depth[i]<<" "<<tin[i]<<" "<<tout[i]<<endl;
    // }

    REP(i,0,m){
        int k;
        cin>>k;
        vector<int> vertices(k);
        int j;
        REP(j,0,k){
            int x;
            cin>>x;
            vertices[j] = x;
        }

        // Replacing 
        int u = vertices[0];
        //Finding deepest vertex
        for(auto it : vertices){
            if(depth[u]<depth[it]) u = it;
        }
        //Replacing each vertex by its parent ; intuiton behind a distance of 1
        for(auto &it : vertices){
            if(it == u) continue;
            if(parent[it]!=-1) it = parent[it];
        }

        bool flag = true;

        for(auto it : vertices) flag = flag & isAncestor(it, u);

        if(flag)cout<<"YES\n";
        else cout<<"NO\n";

    }

    return 0;
}