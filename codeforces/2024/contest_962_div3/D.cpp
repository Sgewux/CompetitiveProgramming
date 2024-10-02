#include <bits/stdc++.h>
#define ll long long

void solve(){
    ll n;
    ll x;
    ll ans = 0;
    std::cin>>n>>x;

    for(long long a = 1; a<=n; a++){
        for(long long b = 1; b<=(n/a); b++){
            if (std::min(x-a-b, (n-a*b)/(a+b)) > 0) ans += std::min(x-a-b, (n-a*b)/(a+b));
        }
    }

    std::cout<<ans<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;

    while(t--){
        solve();
    }

    return 0;
}