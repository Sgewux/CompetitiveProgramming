#include <bits/stdc++.h>
std::vector<long long> memo(1e5 + 1, -1);

long long dp(long long i, std::vector<long long>&s){
    if(i - 2 < 0){
        return std::abs(s[i]-s[0]);
    } else {
        if(memo[i-1] == -1){
            memo[i-1] = dp(i-1, s);
        }

        if(memo[i-2] == -1){
            memo[i-2] = dp(i-2, s);
        }

        return std::min(memo[i-1] + std::abs(s[i] - s[i-1]), memo[i-2] + std::abs(s[i] - s[i-2]));
    }
}

void solve(){
    long long n;
    std::cin>>n;
    std::vector<long long>s(n);
    
    for(long long i = 0; i<n; i++){
        std::cin>>s[i];
    }

    std::cout<<dp(n-1, s);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t=1;

    while(t--){
        solve();
    }

    return 0;
}