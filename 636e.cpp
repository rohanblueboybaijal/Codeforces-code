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

const int N = 200000 +5;
vector<vector<int>> G[N];
vector<int> path1;
vector<int> path2; 
vll p;
int n,m,a,b,c;
int pred[N], dist[N];

bool bfs(int src, int dest){
    list<int> q;
    bool visited[N];
    int i;
    REP(i,0,n+1){
        visited[i] = false;G = vector<vector<int>>(n+1);
        dist[i]= INT_MAX;
        pred[i] = -1;
    }

    visited[src] = true;
    dist[src] = 0;
    q.PB(src);

    while(!q.empty()){
        int u = q.front();
        q.pop_front();
        for(i=0;i<G[u].size(); i++){
            if(visited[G[u][i]]==false){
                visited[G[u][i]]= true;
                dist[G[u][i]] = dist[u] + 1;
                pred[G[u][i]] = u;
                q.push_back(G[u][i]);
            }

            if(G[u][i]==dest){
                return true;
            }
        }
    }
    return false;
}

void shortest_dist(int src, int dest){
    if(bfs(src,dest)==false) {
        cout<<"No path";
        return;
    }

    vector<int> path;
    int crawl = dest;
    path.push_back(crawl);
    while(pred[crawl]!=-1){
        path.push_back(pred[crawl]);
        crawl = pred[crawl];
    }
    cout<<"Distance is "<<dist[dest]<<endl;
    for(int i= path.size()-1; i>=0;i--){
        cout<<path[i]<<" ";
    }
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