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
#define REPr(i,a,n) for(i=(n-1);i>=(a);i-=1)

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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k;
    cin>>n>>k;
    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string s;
    bitset<7> proper[10];
    proper[0] = bitset<7>("1110111");
    proper[1] = bitset<7>("0010010");
    proper[2] = bitset<7>("1011101");
    proper[3] = bitset<7>("1011011");
    proper[4] = bitset<7>("0111010");
    proper[5] = bitset<7>("1101011");
    proper[6] = bitset<7>("1101111");
    proper[7] = bitset<7>("1010010");
    proper[8] = bitset<7>("1111111");
    proper[9] = bitset<7>("1111011");

    bitset<7> num[n];
    int i,j;
    REP(i,0,n){
        getline(cin,s);
        num[i]=bitset<7>(s);
    }

    int convert[n][10];
    bitset<7> temp1,temp2;
    REP(i,0,n){
        REP(j,0,10){
            temp1 = num[i]|proper[j];
            temp2 = temp1^num[i];
            convert[i][j] = temp2.count();
            temp2 = proper[j]^temp1;
            if(temp2.count()) convert[i][j]=-1;
        }
    }
    int dp[n][k+1];
    memset(dp, 0, sizeof(dp));

    REP(i,0,10){
        if(convert[n-1][i]>=0 && convert[n-1][i]<=k ){
            dp[n-1][convert[n-1][i]] = 1;
        }
    }
    int x;
    REPr(i,1,n){
        REPL(j,0,k){
            if(dp[i][j]){
                REP(x,0,10){
                    if(convert[i-1][x] + j <=k && convert[i-1][x]>=0){
                       dp[i-1][convert[i-1][x] + j] = 1;
                    } 
                }
            }
        }
    }

    string ans ;
    ll active = k;
    int max_dig = 0;
    ll temp = active;

    REP(i,0,n){
        temp = active;
        REP(x,0,10){
            ll turn_on = convert[i][x];
            if(i==n-1){
                if(turn_on==active){
                    max_dig = x;
                }
            }
            else {
                if(active - turn_on>=0 && turn_on>=0){
                    if(dp[i+1][active - turn_on]){
                        max_dig = x;
                        temp = active - turn_on;
                    }
                }
            }
        }
        active = temp;
        char y = max_dig + '0';
        ans.PB(y);
    }

    if(dp[0][k]) cout<<ans<<endl;
    else cout<<"-1"<<endl;

    return 0;
}