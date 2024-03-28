#include<iostream>

long long solve(long long b, long long c, long long h){
    long long idealBreadLoafs = c + h + 1;
    long long ans;
    if(b < idealBreadLoafs){
        ans = 2*b-1;
    } else { 
        ans = 2*c + 2*h + 1;
    }

    if(ans >=3){
        return ans;
    } else { 
        return 0;
    }
}

int main(){
    long long t;
    long long b;
    long long c;
    long long h;

    std::cin>>t;

    for(long long i = 0; i < t; i++){
        std::cin>>b;
        std::cin>>c;
        std::cin>>h;

        std::cout<<solve(b,c,h)<<'\n';

    }
    return 0;
}