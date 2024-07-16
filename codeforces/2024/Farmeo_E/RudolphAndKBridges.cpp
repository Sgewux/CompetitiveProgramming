#include <bits/stdc++.h>

long long minCost(std::vector<long long>& row, long long m, long long d){
    std::multiset<long long> req;
    std::vector<long long> mins(m);
    req.insert(1);
    mins[0] = 1;

    for(long long j = 1; j<m-1; j++){
        if(j-(d+2) >= 0){
            req.erase(req.find(mins[j-(d+2)]));
        }

        mins[j] = (*req.begin()) + row[j]+1;
        req.insert(mins[j]);
    }

    if((m-1)-(d+2) >= 0){
        req.erase(req.find(mins[(m-1)-(d+2)]));
    }

    return (*req.begin()) +1;
}

void solve(){
    long long n;
    long long m;
    long long k;
    long long d;
    std::cin>>n;
    std::cin>>m;
    std::cin>>k;
    std::cin>>d;

    std::vector<std::vector<long long>>grid;
    std::vector<long long>p(n+1,0);
    long long ans = 1e18;

    for(long long i = 0; i<n; i++){
        std::vector<long long>row(m);
        for(long long j = 0; j<m; j++){
            std::cin>>row[j];
        }
        grid.push_back(row);
    }


    for(long long i = 1; i<n+1; i++){
        p[i] = p[i-1] + minCost(grid[i-1],m,d);
    }

    for(long long i = k; i<n+1; i++){
        ans = std::min(ans, p[i] - p[i-k]);
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