#include <bits/stdc++.h>

long long leftmostBit(long long b){
    if(b == 0){
        return -1;
    } else {
        long long idx;
        long long i = 0;

        while(b >= pow(2,i)){
            idx = i;
            i++;
        }

        return idx;
    }
}

void solve(){
    long long n;
    long long m;
    std::cin>>n;
    std::cin>>m;

    long long lower = n-m > 0 ? n-m : 0;
    long long upper = n+m;
    
    std::cout << ( (long long)(pow(2, leftmostBit(upper ^ n) + 1) - 1) | n | (long long)(pow(2, leftmostBit(lower ^ n) + 1) - 1)) << '\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;

    while(t--){
        solve();
    }

    return 0;
}