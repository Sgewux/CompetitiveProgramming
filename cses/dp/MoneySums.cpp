#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll maxSum = 100 * 1000 ;
ll dp[maxSum + 1];

void solve(){
    ll n; cin>>n;
    vector<ll>v(n);
    for(long long i = 0; i<n; i++) cin>>v[i];

    memset(dp, 0, sizeof(dp[0]) * (maxSum + 1));

    for(long long i = 0; i<n; i++){
        set<ll> ne;
        
        for(long long j = 1; j<=maxSum; j++){
            if(dp[j]) ne.insert(j + v[i]);
        }

        for(auto& e : ne) dp[e] = 1;
        dp[v[i]] = 1;
    }

    ll ans = 0;
    for(long long i = 0; i<=maxSum; i++) ans += dp[i];

    cout<<ans<<'\n';
    for(long long i = 0; i<=maxSum; i++){
        if(dp[i]) cout<<i<<' ';
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