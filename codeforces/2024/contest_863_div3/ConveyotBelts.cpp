#include <bits/stdc++.h>

long long solve(long long n, long long x1, long long y1, long long x2, long long y2){
    if(n == 2){
        return 0;
    }
    long long b1x = x1 <= n/2 ? x1 : n-x1 + 1;
    long long b1y = y1 <= n/2 ? y1 : n-y1+1;
    long long b1 = std::min(b1x, b1y);
    long long b2x = x2 <= n/2 ? x2 : n-x2 + 1;
    long long b2y = y2 <= n/2 ? y2 : n-y2 + 1;
    long long b2 = std::min(b2x, b2y);

    long long a = std::min( std::abs(b1-b2), std::abs((n-(b1-1)) - (n-(b2-1))) );
    
    return a;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long x1;
    long long y1;
    long long x2;
    long long y2;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::cin>>x1;
        std::cin>>y1;
        std::cin>>x2;
        std::cin>>y2;

        std::cout<<solve(n,x1,y1,x2,y2)<<'\n';
    }

    return 0;
}