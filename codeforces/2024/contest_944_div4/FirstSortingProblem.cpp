#include <bits/stdc++.h>

void solve(){
    long long x;
    long long y;

    std::cin>>x;
    std::cin>>y;

    std::cout<<std::min(x,y) << ' '<<std::max(x,y)<<'\n';
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