#include <bits/stdc++.h>
using namespace std;

#define MP make_pair
#define PB push_back
#define ll long long int
#define F first
#define S second
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)
#define REP(i,n) for(i=0;i<(n);i+=1)
#define REPr(i,n) for(i=n-1;i>=0;i-=1)

typedef vector<ll> vll;
typedef set<int>::iterator sit;
typedef unordered_set<int>::iterator usit;
typedef multiset<int>::iterator msit;
typedef unordered_multiset<int>::iterator umsit;
typedef vector<ll>::iterator vllit;

//cin.ignore(numeric_limits<streamsize>::max(),'\n');

ll LOG(ll a, ll n){
    ll val = 1, x=0;
    while(val < n){
        val = val*a;
        x+=1;
    }
    if(val==n)
        return x;
    else    
        return x-1;
}

const int N = 9;
int m[N][N];

void solve() {
    int i,j;
    int val =2;
    m[0][0] = m[0][0]==1 ? 2:1;
    m[1][3] = m[1][3]==1 ? 2:1;
    m[2][6] = m[2][6]==1 ? 2:1;
    m[3][1] = m[3][1]==1 ? 2:1;
    m[4][4] = m[4][4]==1 ? 2:1;
    m[5][7] = m[5][7]==1 ? 2:1;
    m[6][2] = m[6][2]==1 ? 2:1;
    m[7][5] = m[7][5]==1 ? 2:1;
    m[8][8] = m[8][8]==1 ? 2:1;

    REP(i,9){
        REP(j,9){
            cout<<m[i][j];
        }
        cout<<endl;
    }
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t, i, j, n;
    cin>>t;
    while(t--){
        REP(i,9){
            cin>>n;
            REPr(j,9){
                m[i][j]= n%10;
                n=n/10;
            }
        }
        solve();
    }
    return 0;
}