#include<iostream>
#include<vector>

const unsigned int M = 1000000007;

long long solve(long long current, long long target, long long * coins, long long n, std::vector<long long>& memo){
    long long count = 0;
    if(current == target){
        return 1;
    } else {
        for(long long i = 0; i < n; i++){
            if(current+coins[i] <= target){
                if(memo.at(current+coins[i]) != -1){
                    count += memo.at(current+coins[i]); 
                } else {
                    memo.at(current+coins[i]) = solve(current+coins[i], target, coins, n, memo);
                    count += memo.at(current+coins[i]);
                }
            } else {
                continue;
            }

        }
    }

    return count % M;
}

int main(){
    long long n;
    long long x;
    std::cin>>n;
    std::cin>>x;

    std::vector<long long> memo(x+1, -1);

    long long coins[n];
    for(long long i = 0; i < n; i++){
        std::cin>>coins[i];
    }

    std::cout<<solve(0, x, coins, n, memo);
    return 0;
}