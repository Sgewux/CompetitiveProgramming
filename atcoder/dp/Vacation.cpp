#include <bits/stdc++.h>

const long long N = 1e5 + 1;
std::vector<std::vector<long long>> memo(N, std::vector<long long>(3, -1));

long long dp(long long n, long long row, long long lastChoice, std::vector<std::vector<long long>>& v){
    if(row == n-1){
        long long ans = -1;
        for(long long i = 0; i<3; i++){
            if(i != lastChoice){
                ans = std::max(ans, v[row][i]);
            }
        }

        return ans;
    } else {
        long long ans = -1;

        for(long long i = 0; i<3; i++){
            if(i != lastChoice){
                if(memo[row+1][i] == -1){
                    memo[row+1][i] = dp(n, row+1, i, v);
                }

                ans = std::max(ans, memo[row+1][i] + v[row][i]);
            }
        }

        return ans;
    }
}

void solve(){
    long long n;
    std::cin>>n;
    std::vector<std::vector<long long>> v;

    for(long long i = 0; i<n; i++){
        std::vector<long long>r(3);
        for(long long j = 0; j<3; j++){
            std::cin>>r[j];
        }
        v.push_back(r);
    }

    long long ans = -1;

    if(n == 1){
        std::cout<< std::max(v[0][0], std::max(v[0][1], v[0][2]));
        return;
    }

    for(long long i = 0; i<3; i++){
        ans = std::max(ans, dp(n, 1, i, v) + v[0][i]);
    }

    std::cout<<ans;
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