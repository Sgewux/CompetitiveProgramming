#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll m = 1e9 + 7;
const ll N = 1e6;
ll dp[N+1][3];

ll f(ll n, int w){
    if(n == 1){
        return 1;
    } else {

        ll &r = dp[n][w];

        if(r == -1){
            if(w == 1){
                r = ((4*f(n-1,1) % m) + (f(n-1,2) % m)) % m;
            } else {
                r = ( (2*f(n-1, 2) % m) + (f(n-1, 1) % m)) % m;
            }

        }

        return r;

    }
}

void solve(){
    ll n; cin>>n;
    ll ans = f(n,1) + f(n,2);
    if(ans >= m) ans-= m;
    
    cout<<ans<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    memset(dp, -1, sizeof(dp[0][0]) * (N+1) * (3));
    dp[1][1] = 1;
    dp[1][2] = 1;
    long long t;
    std::cin>>t;

    while(t--){
        solve();
    }

    return 0;
}