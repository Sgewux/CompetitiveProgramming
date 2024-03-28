#include <bits/stdc++.h>

void solve(long long n, long long k){
    long long j = n-k;
    for(long long i = j; i>=1; i--){
        std::cout<<i<<' ';
    }
    for(long long i = 1; i<=n-j; i++){
        std::cout<<j+i<<' ';
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long k;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::cin>>k;

        if(k!=0){
            solve(n,k);
        } else {
            for(long long i = n; i>=1; i--){
                std::cout<<i<<' ';
            }
        }
        std::cout<<'\n';
    }

    return 0;
}