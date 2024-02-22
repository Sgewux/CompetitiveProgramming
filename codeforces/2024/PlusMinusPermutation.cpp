#include <bits/stdc++.h>

long long solve(long long n, long long x, long long y){
    long long g = std::gcd(x,y);
    long long a = y/g;
    long long b = x/g;
    long long x_limit = std::floor(n/x);
    long long y_limit = std::floor(n/y);

    long long overlapped = std::min(std::floor(x_limit/a), std::floor(y_limit/b));

    x_limit -= overlapped;
    y_limit -= overlapped;

    long long ans = ( (n)*(n+1)/2 - (n-x_limit)*(n-x_limit+1)/2 ) - ( (y_limit)*(y_limit+1)/2 );

    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long x;
    long long y;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::cin>>x;
        std::cin>>y;

        std::cout<<solve(n,x,y)<<'\n';
    }

    return 0;
}