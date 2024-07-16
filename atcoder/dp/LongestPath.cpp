#include <bits/stdc++.h>

const long long N = 1e5+1;
std::vector<long long> adj[N];
std::vector<long long> memo(N,-1);

long long dp(long long node){
    if(adj[node].size() == 0){
        return 0;
    } else {
        long long ans = -1;
        for(auto& n : adj[node]){
            if(memo[n] == -1){
                memo[n] = dp(n);
            }
            ans = std::max(ans, 1 + memo[n]);
        }

        return ans;
    }
}

void solve(){
    long long n;
    long long m;
    long long ans = -1;
    std::cin>>n;
    std::cin>>m;
    
    for(long long j = 0; j<m; j++){
        long long a;
        long long b;
        std::cin>>a;
        std::cin>>b;

        adj[a].push_back(b);
    }

    for(long long i = 1; i<=n; i++){
        ans = std::max(ans, dp(i));
    }

    std::cout<<ans;

}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t = 1;

    while(t--){
        solve();
    }

    return 0;
}