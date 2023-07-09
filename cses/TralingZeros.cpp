#include<iostream>
#include<cmath>
#include<vector>

long long solve(long long n){
    long long k = std::floor(n/5);
    std::vector<long long> nums;
    long long p;
    long long a = 0;
    long long b = 0;
    long long i=1;

    while ( (p=std::floor(k/std::pow(5,i))) != 0 )
    {
        nums.push_back(p);

        if(i>1){
            nums[i-2] = nums[i-2]-p;
        }

        i++;
    }

    i = 2;

    for(long long item : nums){
        a+=item;
        b+=item*i;
        i++;
    }
    
    return (k-a) + b;
}

int main(){
    long long n;
    std::cin >> n;
    std::cout << solve(n);
    return 0;
}