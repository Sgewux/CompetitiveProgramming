#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin>>n;
    std::vector<std::pair<long long,long long>>m(n);
    long long t=0;
    long long p=0;
    long long minP = 1e12+1;

    for(long long i = 0; i<n; i++){
        std::cin>>m[i].first;
        std::cin>>m[i].second;
    }

    for(long long i = 0; i<n; i++){
        t+=m[i].first;
        m[i].second = std::min(m[(i == n-1 ? 0 : i+1)].first , m[i].second);
        p+=m[i].second;
        minP = std::min(minP, m[i].second);
    }

    std::cout<<t-(p-minP)<<'\n';
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