#include <bits/stdc++.h>

const int N = 1e6;
std::vector<int> adj[N];
bool visited[N] = {false};

long long dfs(int node){
    if(visited[node]){
        return 0;
    } else {
        visited[node] = true;
        long long vis = 1;

        for(auto& n : adj[node]){
            vis += dfs(n);
        }

        return vis;
    }
}

void solve(){
    long long n;
    long long m;
    long long cantOfFloors = 0;
    long long cantOfVisited = 0;
    long long ans = 0;
    std::string curr;
    std::vector<std::string>b;
    std::cin>>n;
    std::cin>>m;
    std::cin.ignore();

    for(long long i = 0; i<n; i++){
        std::getline(std::cin, curr);
        b.push_back(curr);
    }

    for(long long i = 0; i<n; i++){
        for(long long j = 0; j<m; j++){
            if(b[i][j] == '.'){
                cantOfFloors++;

                if(i-1 >= 0){
                    if(b[i-1][j] == '.'){
                        adj[m*i + j].push_back(m*(i-1) + j);
                    }
                }

                if(i+1 < n){
                    if(b[i+1][j] == '.'){
                        adj[m*i + j].push_back(m*(i+1) + j);
                    }
                }

                if(j+1 < m){
                    if(b[i][j+1] == '.'){
                        adj[m*i + j].push_back(m*i + j + 1);
                    }
                }

                if(j-1 >= 0 ){
                    if(b[i][j-1] == '.'){
                        adj[m*i + j].push_back(m*i + j -1);
                    }
                }
            }
        }
    }

    for(long long i = 0; i<n; i++){
        for(long long j = 0; j<m; j++){
            if(cantOfVisited == cantOfFloors){
                break;
            }

            if(b[i][j] == '.'){
                if(!visited[m*i + j]){
                    cantOfVisited += dfs(m*i + j);
                    ans++;
                }
            }
        }
    }

    std::cout<<ans;
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