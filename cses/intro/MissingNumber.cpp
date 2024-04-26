#include<iostream>

long long solve(long long sum, long long n){

    return (n*(n+1)/2) - sum;
}

int main(){
    long long n;
    long long sum = 0;

    std::cin>>n;

    for(long long i = 0; i < n-1; i++){
        long long a;
        std::cin>>a;
        sum+=a;
    }

    std::cout<<solve(sum, n);
    return 0;
}