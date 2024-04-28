#include <bits/stdc++.h>

const int N = 1e6;
std::vector<int> adj[N];
bool visited[N] = {false};
int team[N];

bool bfs(int node){
    std::queue<int> q;
    visited[node] = true;
    team[node] = 1;
    q.push(node);

    while(!q.empty()){
        int curr = q.front();
        q.pop();
        
        for(auto& n : adj[curr]){
            if(!visited[n]){
                visited[n] = true;
                team[n] = (team[curr] % 2) + 1; 
                q.push(n);
            } else if (team[n] != (team[curr] % 2) + 1){
                return false;
            }
        }
    }

    return true;
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

    bool possible = true;
    for(long long i = 1; i<=n; i++){
        if(!visited[i]){
            possible = possible && bfs(i);
        }
    }

    if(possible){
        for(long long i = 1; i<=n; i++){
            std::cout<<team[i]<< ' ';
        }
    } else {
        std::cout<<"IMPOSSIBLE";
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