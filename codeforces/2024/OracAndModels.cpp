#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    long long ans = 1;
    std::cin>>n;
    std::vector<long long>s;
    std::vector<long long>memo(n+1, 1);

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        s.push_back(curr);
    }


    for(long long i = n; i>=1; i--){
        long long j = 2;

        while(i*j <= n){
            if(s[i-1] < s[i*j-1]){
                memo[i] = std::max(memo[i], 1 + memo[i*j]);
            }

            j++;
        }

        ans = std::max(ans, memo[i]);
    } 

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