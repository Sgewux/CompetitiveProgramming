#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>
 
const long long INF = 1e9;
 
 
long long solve(long long target, long long * coins, long long n, std::vector<long long>  &memo){
    long long count = INF;
 
    if(target==0){
        return 0;
    } else if(target < 0){
        return INF;
    } else {
        for(long long i = 0; i < n; i++){
            if(target-*(coins+i) >= 0 && memo.at(target-*(coins+i)) != -1){
                count = std::min(count, memo.at(target-*(coins+i)));
            } else {
                count = std::min(count, solve(target-*(coins+i), coins, n, memo));
            }
            
        }
        memo.at(target) = count+1;
        return count + 1;
    }
}
 
int main(){
    long long n;
    long long x;
    long long num;
    std::cin>>n;
    std::cin>>x;
 
    long long coins[n];
    std::vector<long long> memo(x+1, -1);
 
    for(long long i = 0;  i<n; i++){
        std::cin>>num;
        coins[i] = num;
    }
 
    long long answer = solve(x, coins, n, memo);
    answer >= INF ? std::cout<<-1 : std::cout<<answer;
 
    return 0;
}