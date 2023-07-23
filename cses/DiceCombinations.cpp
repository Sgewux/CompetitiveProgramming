#include<iostream>
#include<unordered_map>

const unsigned int M = 1000000007;

long long solve(long long current, long long target, std::unordered_map<long long, long long> * memo){
    long long count = 0;
    
    if(current == target){
        return 1;
    } else if(current > target){
        return 0;
    } else {
        for(int i = 1; i <= 6; i++){
            if(memo->count(current+i)){
                count += ((*memo)[current+i]);
            } else {
                (*memo)[current+i] = solve(current+i, target, memo);
                count += ((*memo)[current+i]);
            }
        }
    }

    return count % M;
}

int main(){
    long long n;
    std::cin>>n;
    std::unordered_map<long long, long long> memo;

    std::cout<<solve(0,n,&memo);
    return 0;
}