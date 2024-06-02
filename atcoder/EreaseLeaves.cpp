#include <bits/stdc++.h>

const int N = 3e5 + 1;
std::vector<int> adj[N];
bool visited[N] = {false};

int dfs(int node){
    if(visited[node]){
        return 0;
    } else {
        int cnt = 1;
        visited[node] = true;

        for(auto& n : adj[node]){
            cnt += dfs(n);
        }

        return cnt;
    }
}

void solve(){
    long long n;
    int u;
    int v;
    int degree = 0;
    int ans = 1;
    std::vector<int> subTrees;
    std::cin>>n;

    for(long long i = 0; i<n-1; i++){
        std::cin>>u;
        std::cin>>v;

        if(u != 1 && v != 1){
            adj[u].push_back(v);
            adj[v].push_back(u);
        } else {
            degree++;
            
            if(u!=1){
                subTrees.push_back(u);
            } else {
                subTrees.push_back(v);
            }
        }
     }

    for(long long i = 0; i<degree; i++){
        subTrees[i] = dfs(subTrees[i]);
    }

    std::sort(subTrees.begin(), subTrees.end());

    for(long long i = 0; i<degree-1; i++){
        ans+=subTrees[i];
    }

    std::cout<<ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    t = 1;

    while(t--){
        solve();
    }

    return 0;
}