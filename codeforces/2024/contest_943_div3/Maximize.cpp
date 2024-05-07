#include <bits/stdc++.h>

void solve(){
    long long x;
    long long ans = -1;
    long long y = -1;
    std::cin>>x;

    for(long long i = 1; i<x; i++){
        long long curr = std::gcd(x,i) + i;
        if(curr > ans){
            ans = curr;
            y = i;
        }
    }

    std::cout<<y<<'\n';
    
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