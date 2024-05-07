#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin>>n;
    std::cin.ignore();
    std::set<std::pair<long long, long long>> visited;
    std::vector<std::string> m;
    std::string curr;

    for(long long i = 0; i<n; i++){
        std::getline(std::cin, curr);
        m.push_back(curr);
    }

    long long ans = 0;

    for(long long i = 0; i<n; i++){
        for(long long j = 0; j<n; j++){
            long long zeros = 0;
            long long ones = 0;

            if(i == j && (n%2 != 0)){
                continue;
            }

            std::vector<std::pair<long long, long long>> cords;
            cords.push_back({i,j});
            cords.push_back({n-1-j, i});
            cords.push_back({n-1-i, n-1-j});
            cords.push_back({j, n-1-i});

            for(auto& cord : cords){
                if(visited.count(cord)){
                    zeros = 4;
                    ones = 4;
                    break;
                }

                if(m[cord.first][cord.second] == '1'){
                    ones++;
                } else {
                    zeros++;
                }

                visited.insert(cord);
            }

            ans += 4 - std::max(zeros, ones);

        }
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