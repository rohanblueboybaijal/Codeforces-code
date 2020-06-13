#include <bits/stdc++.h>

#define MP make_pair
#define PB push_back
#define ll long long int
#define F first
#define S second
#define MAX(x,y) (x)>(y)?(x):(y)
#define MIN(x,y) (x)<(y)?(x):(y)

using namespace std;

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


void func(){
    int n, i;
    cin>>n;
    ll x,max_so_far;
    max_so_far= LONG_MIN;
    ll dif =0;
    double ans ;
    for(i=0;i<n;i+=1){
        cin>>x;
        if(x>max_so_far){
            max_so_far = x;
        }
        dif = MAX(dif, max_so_far - x);
    }
    /*for(i=0; dif>0; i+=1){
        dif = dif>>1;
    }*/
    cout<<LOG(2, dif) + 1<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
        func();
    return 0;
}