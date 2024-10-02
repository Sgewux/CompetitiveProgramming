#include <bits/stdc++.h>
#define ll long long

void solve(){
    ll n;
    std::cin>>n;
    std::vector<std::vector<ll>>adj(2*n +1);
    std::vector<std::string> grid(2);
    std::cin.ignore();
    for(long long i = 0; i<2; i++){
       std::getline(std::cin, grid[i]);
    }

    for(long long i = 0; i<2; i++){
        for(long long j = 0; j<n; j++){
            if(grid[i][j] == '.'){
                if(i-1 >= 0 && grid[i-1][j] == '.'){
                    adj[n*i + j].push_back(n*(i-1) + j);
                }

                if(i+1 < 2 && grid[i+1][j] == '.'){
                    adj[n*i + j].push_back(n*(i+1) + j);
                }

                if(j-1 >= 0 && grid[i][j-1] == '.'){
                    adj[n*i + j].push_back(n*i + (j-1));
                }
                if(j+1 < n && grid[i][j+1] == '.'){
                    adj[n*i + j].push_back(n*i + (j+1));
                }
            }
        }
    }

    ll ans = 0;

    for(long long i = 0; i<2; i++){
        for(long long j = 0; j<n; j++){
            if(grid[i][j] == '.' && adj[n*i + j].size() == 3){
                bool si = false;
                std::set<ll>myadj;
                for(auto & nod : adj[n*i + j]){
                    myadj.insert(nod);
                    if(adj[nod].size() == 1 && nod != (n*i + j) +1 && nod != (n*i+j)- 1) si = true;
                }


                if(si) ans++;
            }
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