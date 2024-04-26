#include <bits/stdc++.h>

void dfs(int node, std::vector<int> adj[], bool visited[]){
    if(visited[node]){
        return;
    } else {
        visited[node] = true;

        for(auto& n : adj[node]){
            dfs(n, adj, visited);
        }
    }
}

void solve(){
    long long n;
    std::cin>>n;
    std::cin.ignore();
    std::vector<std::string>m ={"", ""};
    std::getline(std::cin, m[0]);
    std::getline(std::cin, m[1]);

    std::vector<int> adj[2*n];
    bool visited[2*n] = {false};

    for(long long i = 0; i<2; i++){
        for(long long j = 0; j<n; j++){
            int neighbor;
            if(i-1 >= 0){
                neighbor = n*(i-1) + j;
                m[i-1][j] == '>' ? neighbor++ : neighbor--;
                adj[n*i + j].push_back(neighbor);
            }

            if(i+1 <= 1){
               neighbor = n*(i+1) + j;
                m[i+1][j] == '>' ? neighbor++ : neighbor--;
                adj[n*i + j].push_back(neighbor);
            }

            if(j+1 < n){
               neighbor = n*i + j+1;
                m[i][j+1] == '>' ? neighbor++ : neighbor--;
                adj[n*i + j].push_back(neighbor);
            }

            if(j-1 >=0 ){
               neighbor = n*i + j-1;
                m[i][j-1] == '>' ? neighbor++ : neighbor--;
                adj[n*i + j].push_back(neighbor);
            }
        }
    }

    dfs(0, adj, visited);

    std::cout<<(visited[2*n-1] ? "YES" : "NO")<<'\n';
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