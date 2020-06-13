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

bool compare(string s1, string s2){
    // if(s1.length()!=s2.length()){
    //     return s1.length() < s2.length();
    // }
    bool flag = true;
    int len1 = s1.length();
    int len2 = s2.length();
    if(len1!=len2) {
        if(len1 > len2) flag = false;
    }
    int len = min(len1, len2);
    for(int i=0;i<len; i++){
        if(s1[i]!=s2[i]){
            return s1[i]<s2[i];
        }
    }
    return flag;
}

void solve(){
    int n,k,i;
    cin>>n>>k;
    string s;
    vector<char> str;
    vector<string> ans(k); 

    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    cin>>s;
    REP(i,0,n){
        str.PB(s[i]);
    }
    sort(str.begin(), str.end());
    REP(i,0,n) {
        ans[i%k].PB(str[i]);
    }
    sort(ans.begin(), ans.end(), compare);
    // REP(i,0,k) {
    //     cout<<ans[i]<<endl;
    // }

    cout<<ans[k-1]<<endl;
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