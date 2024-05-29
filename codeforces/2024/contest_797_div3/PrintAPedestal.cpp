#include <bits/stdc++.h>

void solve(){
    long long n;
    std::vector<long long> h = {2, 3, 1};
    std::cin>>n;
    n-=6;

    for(long long i = 0; i<3; i++){
        h[i] += std::floor(n/3);
    }

    if(n%3 == 2){
        h[0]++;
        h[1]++;
    } else if(n%3 == 1){
        h[1]++;
    }

    for(long long i = 0; i<3; i++){
        std::cout<<h[i]<<' ';
    }

    std::cout<<'\n';
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