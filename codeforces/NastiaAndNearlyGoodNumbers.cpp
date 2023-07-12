#include<iostream>

void solve(long long A, long long B){
    long long n;
    long long k;
    if(B%2 != 0){
        n=(B-1)/2;
        k=(B+1)/2;
        std::cout<<"YES"<<std::endl;
        std::cout<<A*(n) << " " << A*(k) << " " << A*(n)+A*(k) <<std::endl;
    } else if(B == 2){

        std::cout<<"YES"<<std::endl;
        std::cout<<A << " " << A*(4) << " " << A+A*(4) <<std::endl;
    } else {
        n = (B/2) - 1;
        k = (B/2) + 1;

        std::cout<<"YES"<<std::endl;
        std::cout<<A*(2*n) << " " << A*(2*k) << " " << A*(2*n)+A*(2*k) <<std::endl;
    }
}

int main(){
    long long t;
    long long A;
    long long B;
    std::cin>>t;
    for(long long i = 0; i<t; i++){
        std::cin>>A;
        std::cin>>B;

        if(B == 1){
            std::cout<<"NO"<<std::endl;
        } else {
            solve(A,B);
        }
    }
    return 0;
}