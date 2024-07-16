#include <bits/stdc++.h>

std::vector<long long> memo(1e5 + 1, -1);

long long dp(long long i, long long k, std::vector<long long>&s){
    if (i==0){
        return 0;
    } else {
        long long ans = 1e18;
        for(long long j = 1; j<=k && i-j>=0; j++){
            if(memo[i-j] == -1){
                memo[i-j] = dp(i-j, k, s);
            }
 
            ans = std::min(ans, memo[i-j] + std::abs(s[i]-s[i-j]));
        }
        
        return ans;
    }
}

void solve(){
    long long n;
    long long k;
    std::cin>>n;
    std::cin>>k;
    std::vector<long long>s(n);
    
    for(long long i = 0; i<n; i++){
        std::cin>>s[i];
    }

    std::cout<<dp(n-1, k, s);
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