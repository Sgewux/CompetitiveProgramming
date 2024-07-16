#include <bits/stdc++.h>
long long n;
long long m;

long long maxSum(int i, int j, std::vector<std::vector<int>>& grid, std::vector<std::vector<long long>>& memo){

    if(i == n-1 && j == m-1){
        return grid[i][j];
    } else if(i>n-1 || j>m-1){
        return -1e9;
    } else {
        if(memo[i][j] != -1){
            return memo[i][j];
        } else {
            long long r = maxSum(i, j+1, grid, memo);
            long long d = maxSum(i+1, j, grid, memo);

            memo[i][j] = std::max(r, d) + grid[i][j];
            
            return memo[i][j];
        }
    }
}

long long minSum(int i, int j, std::vector<std::vector<int>>& grid, std::vector<std::vector<long long>>& memo){

    if(i == n-1 && j == m-1){
        return grid[i][j];
    } else if(i>n-1 || j>m-1){
        return 1e9;
    } else {
        if(memo[i][j] != -1){
            return memo[i][j];
        } else {
            long long r = minSum(i, j+1, grid, memo);
            long long d = minSum(i+1, j, grid, memo);

            memo[i][j] = std::min(r, d) + grid[i][j];
            
            return memo[i][j];
        }
    }
}

void solve(){

    std::cin>>n;
    std::cin>>m;
    std::vector<std::vector<int>> grid;
    std::vector<std::vector<long long>> memoMax(n, std::vector<long long>(m, -1));
    std::vector<std::vector<long long>> memoMin(n, std::vector<long long>(m, -1));

    for(long long i = 0; i<n; i++){
        std::vector<int> row(m);
        for(long long j = 0; j<m; j++){
            std::cin>>row[j];
        }
        grid.push_back(row);
    }

    long long max = maxSum(0,0, grid, memoMax);
    long long min = minSum(0,0, grid, memoMin);

    if((min<=0 && max>=0) && (std::abs(min)%2 == 0 && std::abs(max)%2 == 0)){
        std::cout<<"YES"<<'\n';
    } else {
        std::cout<<"NO"<<'\n';
    }
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