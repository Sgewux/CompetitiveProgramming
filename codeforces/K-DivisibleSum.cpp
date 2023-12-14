#include <bits/stdc++.h>

long long smallestHalf(long long n, long long k){
    if(n <= k){
        return n;
    }

    if(n%2 == 0){
        return smallestHalf(n/2, k);
    } else {
        long long half1 = std::floor(n/2);
        long long half2 = std::floor(n/2) + 1;

        return std::min(smallestHalf(half1, k), smallestHalf(half2, k));
    }
}

long long solve(long long n, long long k){
    if(n == 1){
        return k;
    } else if ((n % k) == 0){
        return 1;
    } else if (n < k){
        if((k % n) == 0){
            return k / n;
        } else {
            return std::floor(k / n) + 1;
        }
    } else if( n > k){
        long long newn = smallestHalf(n,k);

        if((k % newn) == 0){
            return k / newn;
        } else {
            return std::floor(k / newn) + 1;
        }
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

        std::cout<<solve(n,k) << '\n';
    }

    return 0;
}