#include <bits/stdc++.h>

long long solve(std::unordered_map<long long, long long>& lastIdx, long long least, long long gratest){
    long long i = -2;
    long long j = 1;
    long long lastIdxA;
    long long lastIdxB;
    std::vector<std::pair<long long, long long>> candidates;

    for(long long a = least; a<=gratest; a++){
        for(long long b = a; b<=gratest; b++){
            if(std::gcd(a,b) == 1){
                std::pair<long long, long long>p(a,b);
                candidates.push_back(p);
            }
        }
    }

    for(auto candidate : candidates){
        if(lastIdx.count(candidate.first) && lastIdx.count(candidate.second)){
            lastIdxA = lastIdx[candidate.first];
            lastIdxB = lastIdx[candidate.second];

            if((i + j) < (lastIdxA + lastIdxB)){
                i = lastIdxA;
                j = lastIdxB;
            }
        }
    }

    return i+j;

}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long current;
    long long least;
    long long greatest;
    std::cin>>t;
    while(t--){
        least = 10e9;
        greatest = -1;
        std::cin>>n;
        std::unordered_map<long long, long long> lastIdx; // elem, last idx
        for(long long i = 0; i < n; i++){
            std::cin>>current;
            lastIdx[current] = i+1;

            greatest = std::max(greatest, current);
            least = std::min(least, current);
        }

        std::cout<<solve(lastIdx, least, greatest)<<'\n';

    }

    return 0;   
}