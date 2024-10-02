#include<bits/stdc++.h>
#define ll long long
 
ll balance(ll node, std::vector<ll>& a, std::vector<std::vector<ll>>& adj){
    if(adj[node].size() == 0){
        return a[node-1];
    } else {
        ll minChild = 1e9 +1;
        for(auto& n : adj[node]){
            minChild = std::min(minChild, balance(n, a, adj));
        }
        
        if(node == 1){
            return a[node-1] + minChild;
        } else {
            if( minChild > a[node-1]) {
               return (a[node-1] + minChild)/2; 
            } else {
                return minChild;
            }
        }
    }
}
 
void solve(){
    ll n;
    ll curr;
    std::cin>>n;
    std::vector<ll> a(n);
    std::vector<std::vector<ll>> adj(n+1);
    
    for(ll i = 0; i<n; i++){
        std::cin>> a[i];
    }
    
    for(ll i = 2; i <= n; i++){
        std::cin>>curr;
        adj[curr].push_back(i);
    }
    
    std::cout<<balance(1,a,adj)<<'\n';
    
}
 
int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    
    ll t;
    std::cin>>t;
    
    while(t--){
        solve();
    }
}