#include <bits/stdc++.h>

void solve(){
    long long n;
    long long m;
    long long x;

    std::cin>>n;
    std::cin>>m;
    std::cin>>x;

    std::vector<std::pair<int, char>> moves(m);
    std::vector<std::pair<int, int>> c(n+1);

    for(long long i = 0; i<=n; i++){
        c[i] = {i, -1};
    }

    c[x].second = 0;

    for(long long j = 0; j<m; j++){
        long long a;
        char b;
        std::cin>>a;
        std::cin>>b;

        std::vector<std::pair<int, int>> copy;

        for(long long i = 0; i<=n; i++){
            copy.push_back(c[i]);
        }

        for(long long i = 1; i<=n; i++){
            if(c[i].second == j){
                if(b == '0'){
                    long long idx = (c[i].first + a)%n == 0 ? n : (c[i].first + a)%n;
                    copy[idx].second = j+1;

                } else if(b == '1'){
                    long long idx = (c[i].first - a > 0 ?  c[i].first - a : n - std::abs( c[i].first - a));

                    copy[idx].second = j+1;

                } else {
                    long long idx1 = (c[i].first + a)%n == 0 ? n : (c[i].first + a)%n;
                    long long idx2 = (c[i].first - a > 0 ?  c[i].first - a : n - std::abs( c[i].first - a));
                    copy[idx1].second = j+1;
                    copy[idx2].second = j+1;

                }
            }

            
        }

        c = copy;
  
    }
    
    long long ans = 0;

    for(long long i = 0; i<=n; i++){
        if(c[i].second == m){
            ans++;
        }
    }

    std::cout<<ans<<'\n';

    for(long long i = 0; i<=n; i++){
        if(c[i].second == m){
            std::cout<<c[i].first<<' ';
        }
    }

    std::cout<<'\n';
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