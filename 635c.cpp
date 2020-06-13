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

bool compareinfo(info i1, info i2){
    if(i1.d > i2.d)
        return i1.d > i2.d;
    else 
        return i1.size<i2.size;
}

const int N = 2e5 + 7;

vector<int> adj[N];
queue<int> q;
bitset<200001> used;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;

    // vector<vector<int>> adj(n+1);
    // queue<int> q;
    // bitset<200001> used;

    // vector<info> arr(n+1);

    info arr[n+1];
    arr[0].id=-1;
    arr[0].d=-1;
    //arr[0].p=-2;

    int u,v,i;
    REP(i,1,n){
        cin>>u>>v;
        adj[u].PB(v);
        adj[v].PB(u);
        arr[i].id = i;
    }
    arr[n].id = n;

    q.push(1);
    used[1]=1;
    //arr[1].p = -1;
    arr[1].size = adj[1].size();

    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int u : adj[v]){
            if(!used[u]){
                arr[u].size = adj[u].size();
                used[u] = 1;
                q.push(u);
                arr[u].d = arr[v].d + 1;
                //arr[u].p = v;
            }
        }
    }

    sort(arr, arr + n+1, compareinfo);

    ll happy = 0;

    REP(i,0,k){
        happy += arr[i].d;
        happy = happy - (arr[i].size-1);
    }

    REP(i,0,n){
        cout<<arr[i].id<<" "<<arr[i].d<<" "<<" "<<arr[i].size<<endl;
    }

    cout<<happy<<endl;


    return 0;
}