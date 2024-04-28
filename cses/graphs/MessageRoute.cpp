#include <bits/stdc++.h>

const int N = 1e6;
std::vector<int> adj[N];
bool visited[N] = {false};
int distance[N];

void bfs(int node){
    std::queue<int>q;
    distance[node] = 0;
    visited[node] = true;
    q.push(node);

    while(!q.empty()){
        node = q.front();
        q.pop();
        
        for(auto& n : adj[node]){
            if(!visited[n]){
                visited[n] = true;
                distance[n] = distance[node] + 1;
                q.push(n);
            }
        }
    }
}

std::vector<int> buildPath(int node){
    std::vector<int>p = {node};
    int currDis = distance[node];
    currDis--;

    while(currDis >= 0){
        for(auto& n : adj[node]){
            if(distance[n] == currDis){
                p.push_back(n);
                node = n;
                currDis--;
                break;
            }
        }
    }

    std::reverse(p.begin(), p.end());
    return p;
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

    bfs(1);

    if(!visited[n]){
        std::cout<<"IMPOSSIBLE";
    } else {
        std::cout<<distance[n] + 1<<'\n';
        for(auto& i : buildPath(n)){
            std::cout<<i<<' ';
        }
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