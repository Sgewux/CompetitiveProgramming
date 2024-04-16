#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    long long max = -1;
    std::vector<long long> v;
    std::cin>>n;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        max = std::max(max, curr);
        v.push_back(curr);
    }

    long long z = 0;
    long long y = 0;

    for(long long i = 0; i<n; i++){
        z = std::gcd(z, max-v[i]);
    }

    for(long long i = 0; i<n; i++){
        y += ( max - v[i] )/z;
    }

    std::cout<< y << ' ' << z;

}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t = 1;;
    // std::cin>>t;

    while(t--){
        solve();
    }

    return 0;
}