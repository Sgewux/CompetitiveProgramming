#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin>>n;
    long long ans = std::floor(n/4) + (n%4)/2;

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