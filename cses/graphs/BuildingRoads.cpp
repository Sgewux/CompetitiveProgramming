#include <bits/stdc++.h>

const int N = 1e6;
std::vector<int> adj[N];
bool visited[N] = {false};

void dfs(int node){
    if(visited[node]){
        return;
    } else {
        visited[node] = true;
        for(auto& n : adj[node]){
            dfs(n);
        }
    }
}

void solve(){
    long long n;
    long long m;
    long long a;
    long long b;
    std::cin>>n;
    std::cin>>m;

    for(long long i = 0; i<m; i++){
        std::cin>>a;
        std::cin>>b;

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    long long k = 0;
    std::vector<std::pair<int, int>> roads;
    dfs(1);

    for(long long i = 2; i<=n; i++){
        if(!visited[i]){
            dfs(i);
            k++;
            roads.push_back({1,i});
        }
    }

    std::cout<<k<<'\n';

    for(auto& r : roads){
        std::cout<<r.first<<' '<<r.second<<'\n';
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t = 1;

    while(t--){
        solve();
    }

    return 0;
}