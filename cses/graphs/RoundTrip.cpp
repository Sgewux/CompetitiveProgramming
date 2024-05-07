#include <bits/stdc++.h>

const int N = 2e5 + 1;
std::vector<int> adj[N];
int distance[N];
bool visited[N] = {false};
bool visited_dfs[N] = {false};
std::vector<int> path;

bool dfs(int node){
    if(visited_dfs[node]){
        if(path[0] == path.back() && path.size() > 3){
            return true;
        } else {
            return false;
        }

    } else {
        visited_dfs[node] = true;

        for(auto& n : adj[node]){
            path.push_back(n);
            
            if(dfs(n)){
                return true;
            } else {
                path.pop_back();
            }
        }

        return false;
    }
}

int bfs(int node){
    int cycleMember = -1;
    std::queue<int>q;
    visited[node] = true;
    distance[node] = 0;
    q.push(node);

    while(!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto& n : adj[curr]){
            if(!visited[n]){
                visited[n] = true;
                distance[n] = distance[curr] + 1;
                q.push(n);
            } else if (distance[n] != distance[curr] - 1){
                cycleMember = n;
            }
        }
    }

    return cycleMember;
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

    for(long long i = 1; i<=n; i++){
        if(!visited[i]){
            int cycleMember = bfs(i);

            if(cycleMember != -1){
                path.push_back(cycleMember);
                dfs(cycleMember);
                std::cout<<path.size()<<'\n';
                for(auto& n : path){
                    std::cout<<n<<' ';
                }

                return;
            }
        }
    }

    std::cout<<"IMPOSSIBLE";
    
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