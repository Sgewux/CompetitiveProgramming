#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<set<ll>> toQuery(n+1);
    vector<set<ll>>adj(n+1);
    
    for(ll i = 2; i<=n; i++){
        toQuery[1].insert(i);
    }
    
    bool full = false;
    while(!full){
        full = true;
        
        for(ll i = 1; i<=n;i++){
            if(!toQuery[i].empty()) full = false;
            for(auto& b : toQuery[i]){
                if(!adj[i].count(b)){
                    ll ans;
                    cout<<"? "<<i<<' '<<b<<endl;
                    cin>>ans;
                    if(ans == i){
                        adj[i].insert(b);
                        adj[b].insert(i);
                    } else {
                        toQuery[ans].insert(b);
                    }
                }
            }
            
            toQuery[i].clear();
        }
    }
    
    set<pair<ll,ll>> seen;
    cout<<"! ";
    for(ll i = 1; i<=n; i++){
        for(auto& b : adj[i]){
            pair<ll,ll> p = {i,b};
            if(p.first > p.second) swap(p.first, p.second);
            if(!seen.count(p)) cout<<p.first<<' '<<p.second<<' ';
            seen.insert(p);
        }
    }
    
    cout<<endl;
}

int main(){
    long long t;
    std::cin>>t;

    while(t--){
        solve();
    }

    return 0;
}