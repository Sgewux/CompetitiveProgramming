#include<iostream>

long long solve(long long n){
    long long a;
    long long b;
    long long answerQuality = 0;
    long long answerIdx = 0;
    for(long long i =  1; i<=n; i++){
        std::cin>>a;
        std::cin>>b;

        if(a<=10 && b>answerQuality){
            answerIdx = i;
            answerQuality = b;
        }
    }

    return answerIdx;
}

int main(){
    long long t;
    long long n;
    std::cin>>t;

    for(long long j = 0; j < t; j++){
        std::cin>>n;
        std::cout<<solve(n)<<std::endl;
    }
    return 0;
}