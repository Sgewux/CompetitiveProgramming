#include <bits/stdc++.h>

long long solve(long long m, long long k, long long a1, long long ak){
    if(a1>=m){
        return 0;
    } else if(m%k == 0){
        long long ans = ((m/k)- ak) - std::floor(a1/k);
        return ans < 0 ? 0 : ans;
    } else {
        if(a1 > m%k){
            long long ans = (std::floor(m/k) - ak) - std::floor( (a1-(m%k)) / k);
            return ans < 0 ? 0 : ans;
        } else {
            long long ans = std::floor(m/k) - ak;
            return ans < 0 ? (m%k) - a1 : ans + ((m%k) - a1);
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long m;
    long long k;
    long long a1;
    long long ak;
    std::cin>>t;

    while(t--){
        std::cin>>m;
        std::cin>>k;
        std::cin>>a1;
        std::cin>>ak;

        std::cout<<solve(m,k,a1,ak)<<'\n';
    }

    return 0;
}