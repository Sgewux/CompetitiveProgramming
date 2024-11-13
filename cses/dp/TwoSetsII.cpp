#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll m = 1e9 + 7;
const ll maxSum = 500*500;
ll dp[maxSum + 1];

ll binexpo(ll a, ll b){
    if(b == 0) return 1;
    ll res = binexpo(a, b/2);
    res = (res * res) % m;

    if(b & 1){
        return (res * a) % m;
    } else {
        return res;
    }
}

void solve(){
    ll n; cin>>n;
    memset(dp, 0, sizeof(dp[0]) * (maxSum + 1));
    
    if(n*(n+1)/2 & 1){
        cout<< 0;
        return;
    }

    for(long long i = 1; i<=n; i++){
        for(long long j = maxSum-i; j>=1; j--){
            dp[j + i] += dp[j];
            if(dp[i+j] >= m) dp[i+j] -= m;
        }

        dp[i] += 1;
        if(dp[i] >= m) dp[i] -= m;
    }
    
    ll ans = (dp[n*(n+1)/4] * binexpo(2, m-2)) % m;
    cout << ans;
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