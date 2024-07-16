#include <bits/stdc++.h>
const int N = 3e5+2;
std::set<int> adj[N];
bool visited[N] = {false};
int distance[N];

int f;
int b;

void clean(){
    for(long long i = 0; i<N; i++){
        visited[i] = false;
    }
}
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
void bfs(int node){
    std::queue<int> q;
    q.push(node);
    visited[node] = true;
    distance[node] = 0;

    while (!q.empty()){
        int curr = q.front();
        q.pop();

        for(auto& n : adj[curr]){
            if(!visited[n]){
                visited[n] = true;
                distance[n] = distance[curr] + 1;
                q.push(n);
            }
        }
    }   
}

void breakGraph(int node){
    int a;
    int c;
    int initDis = distance[node]-1;
    int currDis = distance[node]-1;
    while(currDis >= 0){
        for(auto& n : adj[node]){
            if(distance[n] == currDis){
                if(currDis == initDis){
                    a = n;
                }
                if(currDis == 1){
                    c = n;
                }

                node = n;
                currDis--;
                break;
            }
        }
    }

    adj[f].erase(c);
    adj[b].erase(a);

}

void solve(){
    long long n;
    std::cin>>n;
    std::cin>>f;
    std::cin>>b;

    for(long long i = 0; i<n-1; i++){
        int u;
        int v;
        std::cin>>u;
        std::cin>>v;
        adj[u].insert(v);
        adj[v].insert(u);
    }

    bfs(f);
    if(distance[b] == 1){
        adj[b].erase(f);
        adj[f].erase(b);
    } else {
        breakGraph(b);
    }
        
    clean();
    long long sizeF = dfs(f);
    clean();
    long long sizeB = dfs(b);

        std::cout<< n*(n-1) - (sizeF*sizeB)<<'\n';

}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t=1;

    while(t--){
        solve();
    }

    return 0;
}