#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 1e6;
ll n;
ll dp[N + 1];

ll f(ll x){
    if(x == 0){
        return 0;
    } else {
        ll &r = dp[x];

        if(r == -1){
            r = 1e9;
            string s = to_string(x);
            for(auto & c : s){
                r = min(r, 1 + f(x - (int)(c - '0')));
            }
        }

        return r;
    }
}

void solve(){
    cin>>n;
    memset(dp, -1, sizeof(dp[0]) * (N+1));

    cout<<f(n);
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