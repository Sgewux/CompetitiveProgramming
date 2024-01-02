#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    long long totalOnes = 0;
    long long totalZeros = 0;
    long long firstZero = -1;
    long long lastOne = -1;
    long long base = 0;
    std::cin>>n;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        if(curr == 0){
            if(firstZero == -1){
                firstZero = i;
            }
            totalZeros++;
            base += totalOnes;
        } else if(curr == 1){
            lastOne = i;
            totalOnes++;
        }
    }

    long long invertStart = firstZero != -1 ? base + ((totalZeros-1)-firstZero) : -1;
    long long invertEnd = lastOne != -1 ?  base + ((totalOnes-1) - ((n-1) - lastOne)) : -1;

    long long ans = std::max(base, std::max(invertStart, invertEnd));
    std::cout<<ans<<'\n';
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