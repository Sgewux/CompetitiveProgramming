#include <bits/stdc++.h>

void solve(){
    std::vector<long long> v(3);

    for(long long i = 0; i<3; i++){
        std::cin>>v[i];
    }

    long long ans  = 1e9;
    ans = std::min(ans, std::abs(v[0]-v[1]) + std::abs(v[0] - v[2]));
    ans = std::min(ans, std::abs(v[1]-v[0]) + std::abs(v[1] - v[2]));
    ans = std::min(ans, std::abs(v[0]-v[2]) + std::abs(v[2] - v[1]));

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