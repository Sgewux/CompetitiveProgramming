#include <bits/stdc++.h>

void solve(){
    long long n;
    long long m;
    std::cin>>n;
    std::cin>>m;
    std::vector<std::string> grid(n+1);
    std::string s;
    std::cin.ignore();

    for(long long i = 0; i<n; i++){
        std::getline(std::cin, s);
        grid[i] = s;
    }
    s = "";
    for(long long i = 0; i<m; i++){
        s.push_back('.');
    }
    grid[n] = s;

    std::pair<int, int> topMost = {-1,-1};
    long long r;

    for(long long i = 0; i<n+1; i++){
        bool point = false;
        for(long long j = 0; j<m; j++){
            if(grid[i][j] == '#'){
                point = true;
                if(topMost.first == -1 && topMost.second == -1){
                    topMost ={i,j};
                }
            }
        }

        if(point == false && topMost.first != -1 && topMost.second != -1){
            r = (i-topMost.first)/2;
            break;
        }
    }

    std::cout<<topMost.first + r + 1 << ' ' << topMost.second + 1<<'\n';
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