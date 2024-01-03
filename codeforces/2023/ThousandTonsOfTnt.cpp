#include <bits/stdc++.h>

std::unordered_set<long long> getDivisors(long long n){
    std::unordered_set<long long> k = {1,n};
    for(long long i = 2; i <= std::floor(n/2); i++){
        if(n%i == 0){
            if(k.count(n/i) || k.count(i)){
                break;
            } else {
                k.insert(i);
                k.insert(n/i);
            }
        }
    }

    return k;
}

long long solve(long long n, std::vector<long long>&a){
    std::unordered_set<long long> k = getDivisors(n);
    long long ans = -1;

    for(auto div : k){
        long long max;
        long long min;

        for(long long i = 0; i <= n-div; i+=div){
            long long sum = 0;
            for(long long j = 0; j<=div-1; j++){
                sum += a[i+j];
            }

            if(i == 0){
                max = sum;
                min = sum;
            } else {
                max = std::max(sum, max);
                min = std::min(sum, min);
            }

        }

        ans = std::max(ans, max-min);
    }

    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long curr;
    std::vector<long long>a;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        a.clear();
        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            a.push_back(curr);
        }

        std::cout<<solve(n,a)<<'\n';
    }

    return 0;
}