#include <bits/stdc++.h>

void solve(){
    long long x;
    long long y;
    long long z;
    long long k;
    long long ans = 0;

    std::cin>>x;
    std::cin>>y;
    std::cin>>z;
    std::cin>>k;

    for(long long i = 1; i<=x; i++){
        for(long long j = 1; j<=y; j++){
            if(k%(i*j) == 0 && k/(i*j) <= z){
                long long ways = (x-i+1)*(y-j+1)*(z-(k/(i*j)) + 1);
                ans = std::max(ans, ways);
            }
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