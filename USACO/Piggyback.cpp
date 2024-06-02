#include <bits/stdc++.h>

const int N = 4e4 + 1;
std::vector<int> adj[N];
bool visited[N] = {false};
int bDist[N];
int eDist[N];
int fDist[N];

void bfs(int node, int dist[N]){
    std::queue<int> q;
    visited[node] = true;
    dist[node] = 0;
    q.push(node);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto& n : adj[curr]){
            if(!visited[n]){
                visited[n] = true;
                dist[n] = dist[curr] + 1;
                q.push(n);
            }
        }
    }
}

void clearVisited(){
    for(long long i = 0; i<N; i++){
        visited[i] = false;
    }
}

void solve(){
    int b;
    int e;
    int p;
    int n;
    int m;
    int u;
    int v;

    std::cin>>b;
    std::cin>>e;
    std::cin>>p;
    std::cin>>n;
    std::cin>>m;

    for(long long i = 0; i<m; i++){
        std::cin>>u;
        std::cin>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bfs(1, bDist);
    clearVisited();
    bfs(2, eDist);
    clearVisited();
    bfs(n, fDist);

    long long ans = b*fDist[1] + e*fDist[2];

    for(long long i = 1; i<n; i++){
        if(visited[i]){
            ans = std::min(ans, (long long)((b*bDist[i] + e*eDist[i]) + p*fDist[i]) );
        }
    }

    std::cout<<ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::freopen("piggyback.in", "r", stdin);
    std::freopen("piggyback.out", "w", stdout);

    long long t;
    t=1;

    while(t--){
        solve();
    }

    return 0;
}