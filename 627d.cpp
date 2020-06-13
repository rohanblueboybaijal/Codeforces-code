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



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,x;
    cin>>n;
    vector<int> a, b, arr;
    int i;
    REP(i,0,n){
        cin>>x;
        a.PB(x);
    }
    REP(i,0,n){
        cin>>x;
        b.PB(x);
        arr.PB(a[i]-b[i]);
    }
    sort(arr.begin(),arr.end());

    int cnt=0;
    int negpos =-1;
    int newnegpos = -1;
    ll ans=0;

    REP(i,0,n){
        if(arr[i]<=0){
            negpos = i;
            newnegpos=negpos;
            continue;
        }
        else{
            ans += n-1 -i;
            ans += negpos - newnegpos;
            int j=newnegpos;
            while(j>=0){
                if(arr[i] + arr[j]>0)
                    cnt+=1;
                else{
                    newnegpos = j;
                    break;
                }
                j--;
            } 
        }
        ans +=cnt;
        cnt = 0;  
    }
    cout<<ans<<endl;
    return 0;
}