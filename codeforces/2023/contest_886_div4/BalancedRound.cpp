#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>

long long maxConsecutive(long long * nums, long long k, long long n, long long i){
    long long count = 0;
    long long current = nums[i];

    if(i==n){
        return 0;
    }

    while(i<n){
        if(std::abs(nums[i] - current) <= k){
            current = nums[i];
            count++;
            i++;
        } else {
            break;
        }
    }

    return std::max(count, maxConsecutive(nums, k, n, i));
}

int main(){
    long long t;
    long long n;
    long long k;
    long long num;
    std::cin>>t;

    for(long long i = 0; i < t; i ++){
        std::cin>>n;
        std::cin>>k;
        long long nums[n];
        for(long long j = 0; j < n; j++){
            std::cin>>num;
            *(nums + j)=num;
        }

        std::sort(nums, nums+n);

        std::cout<< n - maxConsecutive(nums, k, n, 0)<<std::endl;
    }
    return 0;
}