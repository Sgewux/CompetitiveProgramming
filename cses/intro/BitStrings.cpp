#include<iostream>

const unsigned int M = 1000000007;

long long solve(long long n){
    if(n == 1){
        return 2;
    
    } else if(n == 2){
        return 4;
    }

    long long c = 4;

    for (long long i = 0; i < n-2; i++){
        c = (c*2)%M;
    } 
    
    return c;

}

int main(){
    long long n;

    std::cin >> n;

    std::cout << solve(n);
    return 0;
}