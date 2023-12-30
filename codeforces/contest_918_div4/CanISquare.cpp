#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long curr;
    std::cin>>t;

    while(t--){
        long long sum = 0;
        std::cin>>n;

        for(long long i = 0; i<n; i++){
           std::cin>>curr;
           sum+=curr; 
        }

        std::string ans = (std::sqrt(sum) == std::floor(std::sqrt(sum))) ? "YES" : "NO";
        std::cout<<ans<<'\n';
    }

    return 0;
}