#include <bits/stdc++.h>

const unsigned int M = 1e9 + 7;

long long solve(long long i, long long j, long long h, long long w, std::vector<std::string>& grid, std::vector<std::vector<long long>>& memo){
    long long count = 0;
    if((i == h-1) && (j == w-1)){
        if(grid[i][j] != '#'){
            return 1;
        } else {
            return 0;
        }
    } else if((i>h-1) || (j>w-1)){
        return 0;
    } else if(grid[i][j] == '#'){
        return 0;
    } else {
        if(memo[i][j] != -1){
            count += memo[i][j];
        } else {
            long long r;
            long long d;
            r = solve(i, j+1, h,w, grid, memo);
            d = solve(i+1, j, h,w, grid, memo);
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
    
    long long h;
    long long w;
    std::string curr;
    std::vector<std::string> grid;
    std::cin>>h;
    std::cin>>w;
    std::vector<std::vector<long long>> memo(h, std::vector<long long>(w, -1));
    std::cin.ignore();

    for(long long i = 0 ; i < h; i++){
        std::getline(std::cin, curr);
        grid.push_back(curr);
    }

    std::cout<<solve(0, 0, h, w, grid, memo)<<'\n';

    return 0;
}