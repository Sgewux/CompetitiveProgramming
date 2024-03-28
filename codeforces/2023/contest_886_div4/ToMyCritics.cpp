#include<iostream>
#include<string>

std::string solve(long long * nums, long long sum){
    for(int i = 0; i<3; i++){
        if(sum-*(nums+i) >= 10){
            return "YES";
        }
    }

    return "NO";
}

int main(){
    long long t;
    long long nums[3];
    long long sum;
    long long current;
    std::cin>>t;

    for(long long i = 0; i<t; i++){
        sum = 0;
        for(long long j = 0; j < 3; j++){
            std::cin>>current;
            nums[j] = current;
            sum+=current;
        }

        std::cout<<solve(nums, sum)<<std::endl;
    }
    return 0;
}