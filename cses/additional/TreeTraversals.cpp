#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
void solve(){
    ll n;
    ll curr;
    cin>>n;
    ll m[n+1];
    ll dfs[n];
 
    for(long long i = 0; i<n; i++){
        cin>>curr;
        m[curr] = i;
    }
 
    for(long long i = 0; i<n; i++){
        cin>>dfs[i];
    }
 
    vector<ll>s;
 
    for(long long i = 0; i<n; i++){
        while(!s.empty() && m[dfs[i]] < m[s.back()]){
            cout<<s.back()<<' ';
            s.pop_back();
        }
 
        if(i == n-1 || m[dfs[i]] > m[dfs[i+1]]){
            cout<<dfs[i]<<' ';
        } else {
            s.push_back(dfs[i]);
        }
    }
 
    while(!s.empty()){
        cout<<s.back()<<' ';
        s.pop_back();
    }
}
 
int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
 
    long long t=1;
 
    while(t--){
        solve();
    }
 
    return 0;
}