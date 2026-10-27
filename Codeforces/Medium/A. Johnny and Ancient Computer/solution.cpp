#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin>>n;
    
    string s;
    cin>>s;
    
    int ans=0;
    int cnt=0;
    
    for(int i=0; i<n; i++){
        if(s[i]=='(') cnt++;
        else cnt--;
        
        if(cnt<0){
            ans++;
            cnt++;
        }
    }
    
    cout<<ans<<'\n';
    return;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        solve();
    }
    
    return 0;
}