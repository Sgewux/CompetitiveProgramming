#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 1e3+1;
ll dp[N];
vector<vector<pair<ll,ll>>> adj(N);

ll f(ll i){
    ll &r = dp[i];
    if(r == -1){
        r = 0;
        for(auto& p : adj[i]){
            r = max(r, p.second + f(p.first));
        }
    }

    return r;
}

void solve(){
    ll n; ll m;
    cin>>n>>m;    
    memset(dp, -1, sizeof(dp[0]) * N);
    for(long long i = 0; i<m; i++){
        ll s; ll t; ll c;
        cin>>s>>t>>c;
        adj[s].push_back({t,c});
    }
    ll ans = -1;
    for(long long i = 1; i<=n; i++){
        ans = max(ans, f(i));
    }

    cout<<ans;
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