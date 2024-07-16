#include <bits/stdc++.h>

void solve(){
    std::string s;
    std::string t;
    std::getline(std::cin, s);
    std::getline(std::cin, t);
    long long n = t.length() +1;
    long long m = s.length() + 1;

    std::vector<std::vector<long long>> memo(n, std::vector<long long>(m, 0));
    std::vector<std::vector<std::tuple<int, int, char>>> grid(n, std::vector<std::tuple<int, int, char>>(m));

    for(long long i = 1; i<n; i++){
        for(long long j = 1; j<m; j++){
            if(t[i-1] == s[j-1]){
                memo[i][j] = memo[i-1][j-1] + 1;
                grid[i][j] = {i-1, j-1, s[j-1]};
            } else {
                if(memo[i-1][j] > memo[i][j-1]){
                    memo[i][j] = memo[i-1][j];
                    grid[i][j] = {i-1, j, '\0'};
                } else {
                    memo[i][j] = memo[i][j-1];
                    grid[i][j] = {i,j-1,'\0'};
                }
            }
        }
    }

    long long i = n-1;
    long long j = m-1;
    std::string ans = "";
    while(i > 0 && j > 0){
        if(t[i-1] == s[j-1]){
            ans+=t[i-1];
        }
        long long newi = std::get<0>(grid[i][j]);
        long long newj = std::get<1>(grid[i][j]);
        i = newi;
        j = newj;
    }

    std::reverse(ans.begin(), ans.end());
    std::cout<<ans;
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