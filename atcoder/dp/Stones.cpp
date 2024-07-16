#include <bits/stdc++.h>

long long min = 1e9;
const long long N = 1e6;
std::vector<std::vector<int>> memo(2, std::vector<int>(N, -1));


int dp(int player, long long k, long long n, std::vector<long long>& a){
    if(k < min){
        return !player;
    } else {
        int ans = (player == 0 ? 1 : 0);
        for(long long i = 0; i<n; i++){
            long long x = a[i];
            if(k-x >= 0){
                if(memo[!player][k-x] == -1){
                    memo[!player][k-x] = dp(!player, k-x,n, a);
                }

                ans = (player == 0 ? std::min(ans, memo[!player][k-x]) : std::max(ans, memo[!player][k-x]));
            }

        }

        return ans;
    }
}

void solve(){
    long long n;
    long long k;
    std::cin>>n;
    std::cin>>k;
    std::vector<long long>a(n);

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
        min = std::min(min, a[i]);
    }

    int ans = 1;
    for(long long i = 0; i<n; i++){
        ans = std::min(ans, dp(1, k-a[i],n, a));
    }   

    std::cout<<(ans == 0 ? "First" : "Second");
    
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t = 1;

    while(t--){
        solve();
    }

    return 0;
}