#include<bits/stdc++.h>
using namespace std;

void solve(int n, vector<int>&a){
    long long minh=LLONG_MAX;
    long long prefix=0;
    vector<int> ans(n);
    for(int i=0;i<n;i++){
        prefix+= a[i];
        long long maxh= prefix/(i+1);
        minh= min(minh, maxh);
        ans[i]= minh;
    }
    for(int i=0;i<n;i++){
        cout<<ans[i];
        if(i!=n-1) cout<<" ";
    }
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        solve(n, a);
        cout<<endl;
    }
    return 0;
}
