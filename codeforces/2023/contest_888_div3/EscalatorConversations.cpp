#include<iostream>
#include<cstdlib>

long long solve(long long H, long long * heights, long long n, long long k, long long m){
    long long count = 0;

    for(long long i = 0; i < n; i++){
        long long diff = std::abs(H - *(heights+i));

        if(diff%k == 0 && (diff/k) != 0 && (diff/k) < m){
            count++;
        }
    }

    return count;
}

int main(){
    long long t;
    long long n;
    long long m;
    long long k;
    long long H;

    std::cin>>t;

    for(long long i = 0; i < t; i++){
        std::cin>>n;
        std::cin>>m;
        std::cin>>k;
        std::cin>>H;

        long long heights[n];

        for(long long j = 0; j < n; j++){
            std::cin>>heights[j];
        }

        std::cout<<solve(H, heights, n, k, m)<<std::endl;
    }
    return 0;
}