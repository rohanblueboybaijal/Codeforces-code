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

bool isValid(int r, int c, int n, int m) {
    return r>=1 && r<=n && c>=1 && c<=m;
}

const int N = 60;
char M[N][N];
int dir[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

void solve() {
    int n,m;
    cin>>n>>m;
    char ch;
    int i,j,good=0;
    REPL(i,1,n) {
        REPL(j,1,m) {
            cin>>ch;
            M[i][j]=ch;
        }
    }
    bool flag = true;
    REPL(i,1,n) {
        REPL(j,1,m) {
            if(M[i][j]=='B') {
                int k;
                REP(k,0,4) {
                    int r,c;
                    r = i + dir[k][0];
                    c = j + dir[k][1];
                    if(isValid(r,c,n,m) && M[r][c]=='.') M[r][c]='#';
                }
            }
        }
    }  

    bool visited[N][N];
    memset(visited, false, sizeof(visited));
    queue<pair<int,int>> q;

    if(M[n][m]=='.') {
        q.push({n,m});
        visited[n][m]=true;
    }

    while(!q.empty()) {
        pair<int,int> s = q.front();
        q.pop();
        int r=s.F, c=s.S;
        int k;
        REP(k,0,4) {
            int tr,tc;
            tr = r + dir[k][0];
            tc = c + dir[k][1];
            if(isValid(tr,tc,n,m) && !visited[tr][tc] && M[tr][tc]!='#') {
                q.push({tr,tc});
                visited[tr][tc]=true;
            }
        }
        visited[r][c]=true;
    }

    REPL(i,1,n) {
        if(!flag) break;
        REPL(j,1,m) {
            if(M[i][j]=='G' && !visited[i][j]) flag = false;
            if(M[i][j]=='B' && visited[i][j]) flag = false;
        }
    }
    if(flag) cout<<"Yes";
    else cout<<"No";
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
