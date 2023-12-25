#include <bits/stdc++.h>

const unsigned int M = 1000000007;

long long solve(long long i, long long j, long long n, std::vector<std::string>& grid, std::vector<std::vector<long long>>& memo){
    long long count = 0;
    if((i == n-1) && (j == n-1)){
        if(grid[i][j] != '*'){
            return 1;
        } else {
            return 0;
        }
    } else if((i>n-1) || (j>n-1)){
        return 0;
    } else if(grid[i][j] == '*'){
        return 0;
    } else {
        if(memo[i][j] != -1){
            count += memo[i][j];
        } else {
            long long r;
            long long d;
            r = solve(i, j+1, n, grid, memo);
            d = solve(i+1, j, n, grid, memo);
            memo[i][j] = r + d;
            count += r+d;
        }
    }

    return count % M;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    
    long long n;
    std::string curr;
    std::vector<std::string> grid;
    std::cin>>n;
    std::vector<std::vector<long long>> memo(n, std::vector<long long>(n, -1));
    std::cin.ignore();

    for(long long i = 0 ; i < n; i++){
        std::getline(std::cin, curr);
        grid.push_back(curr);
    }

    std::cout<<solve(0, 0, n, grid, memo)<<'\n';

    return 0;
}