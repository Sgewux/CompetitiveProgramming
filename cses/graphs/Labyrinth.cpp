#include <bits/stdc++.h>

const int N = 1e6;
std::vector<int> adj[N];
bool visited[N] = {false};
int distance[N];

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

std::string buildPath(int node, int m){
    std::string path = "";
    int currDis = distance[node];
    currDis--;

    while(currDis >= 0){
        for(auto& n : adj[node]){
            if(distance[n] == currDis){
                if(n+1 == node){
                    path.push_back('R');
                } else if(n-1 == node){
                    path.push_back('L');
                } else if(n-m == node){
                    path.push_back('U');
                } else {
                    path.push_back('D');
                }

                node = n;
                currDis--;
                break;
            }
        }
    }
    std::reverse(path.begin(), path.end());
    return path;
}

void solve(){
    long long n;
    long long m;
    int A;
    int B;
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
            if(b[i][j] == '.' || b[i][j] == 'A' || b[i][j] == 'B'){

                if(i-1 >= 0){
                    if(b[i-1][j] == '.' || b[i-1][j] == 'A' ||  b[i-1][j] == 'B'){
                        adj[m*i + j].push_back(m*(i-1) + j);
                    }
                }

                if(i+1 < n){
                    if(b[i+1][j] == '.' || b[i+1][j] == 'A' || b[i+1][j] == 'B'){
                        adj[m*i + j].push_back(m*(i+1) + j);
                    }
                }

                if(j+1 < m){
                    if(b[i][j+1] == '.' ||  b[i][j+1] == 'A' || b[i][j+1] == 'B'){
                        adj[m*i + j].push_back(m*i + j + 1);
                    }
                }

                if(j-1 >= 0 ){
                    if(b[i][j-1] == '.' || b[i][j-1] == 'A' || b[i][j-1] == 'B'){
                        adj[m*i + j].push_back(m*i + j -1);
                    }
                }
            }
        
            if(b[i][j] == 'A'){
                A = m*i + j;
            } else if(b[i][j] == 'B'){
                B = m*i + j;
            }
        }

    }

    bfs(A);
    
    if(visited[B]){
        std::string p = buildPath(B, m);
        std::cout<<"YES"<<'\n';
        std::cout<<distance[B]<< '\n';
        std::cout<<p;
    } else {
        std::cout<<"NO";
    }
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