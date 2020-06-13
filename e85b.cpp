#include <bits/stdc++.h>
using namespace std;

void func() {
    int n,x,i;
    cin>>n>>x;
    vector<long long int> a;
    long long int t;
    for(i=0;i<n;i+=1){
        cin>>t;
        a.push_back(t);
    }
    sort(a.begin(), a.end(), greater<long long int>());

    vector <double> sum;
    sum.push_back(a[0]);
    for(i=1;i<n;i+=1) 
        sum.push_back(sum[i-1] + a[i]);

    bool flag = true;
    
    for(i=0;i<n;i+=1){
        if((sum[i]/(i+1))<x)
            break;
    }
    cout<<i<<endl;

}

int main() {
    int t;
    cin>>t;
    while(t--)
        func();
    return 0;
}