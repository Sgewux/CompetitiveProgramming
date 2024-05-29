#include <bits/stdc++.h>

const int INF = 1e8;
const int N = 1e6;
std::vector<int> adj[N];
bool visited[N] = {false};
int mDistance[N];
int aDistance[N];
std::priority_queue<std::pair<int, int>> pq;


std::string buildPath(int node,int m){
    std::string path = "";
    int currDis = aDistance[node];
    currDis--;
    
    while(currDis >= 0){
        for(auto& n : adj[node]){
            if(aDistance[n] == currDis){
                if(n + 1 == node){
                    path.push_back('R');
                } else if(n - 1 == node){
                    path.push_back('L');
                } else if(n- m == node){
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

void dijkstra(){
    while(!pq.empty()){
        int a = pq.top().second;
        pq.pop();
        if(visited[a]){
            continue;
        }

        visited[a] = true;

        for(auto& n : adj[a]){
            if(mDistance[a] + 1 < mDistance[n]){
                mDistance[n] = mDistance[a] + 1;
                pq.push({-mDistance[n], n});
            }
        }
    }
}

void bfs(int node){
    std::queue<int> q;
    aDistance[node] = 0;
    visited[node] = true;
    q.push(node);

    while(!q.empty()){
        int a = q.front();
        q.pop();

        for(auto& n : adj[a]){
            if(!visited[n]){
                visited[n] = true;
                aDistance[n] = aDistance[a] + 1;
                q.push(n);
            }
        }
    }
}

void solve(){
    for(long long i = 0; i<N; i++){
        mDistance[i] = INF;
        aDistance[i] = INF;
    }

    long long n;
    long long m;
    int A;
    int M = -1;
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
            if(b[i][j] == '.' || b[i][j] == 'A' || b[i][j] == 'M'){

                if(i-1 >= 0){
                    if(b[i-1][j] == '.' || b[i-1][j] == 'A' ||  b[i-1][j] == 'M'){
                        adj[m*i + j].push_back(m*(i-1) + j);
                    }
                }

                if(i+1 < n){
                    if(b[i+1][j] == '.' || b[i+1][j] == 'A' || b[i+1][j] == 'M'){
                        adj[m*i + j].push_back(m*(i+1) + j);
                    }
                }

                if(j+1 < m){
                    if(b[i][j+1] == '.' ||  b[i][j+1] == 'A' || b[i][j+1] == 'M'){
                        adj[m*i + j].push_back(m*i + j + 1);
                    }
                }

                if(j-1 >= 0 ){
                    if(b[i][j-1] == '.' || b[i][j-1] == 'A' || b[i][j-1] == 'M'){
                        adj[m*i + j].push_back(m*i + j -1);
                    }
                }
            }
            
            
            if(b[i][j] == 'A'){
                A = m*i + j;
            } else if(b[i][j] == 'M'){
                pq.push({0, m*i + j});
                mDistance[m*i + j] = 0;
            }
                
        }
    }

    // 0-1 BFS from M
    dijkstra();

    for(long long i = 0; i<N; i++){
        visited[i] = false;
    }

    bfs(A);

    for(long long i = 0; i<N; i++){
        visited[i] = false;
    }

    std::string p ;

    for(long long j = 0; j<m; j++){
        if((b[0][j] == '.' || b[0][j] == 'A') && aDistance[j] < mDistance[j] ){
            std::cout<<"YES"<<'\n';
            p = buildPath(j, m);
            std::cout<<p.length()<<'\n';
            std::cout<<p;
            return;
        } else if( (b[n-1][j] == '.' || b[n-1][j] == 'A') && aDistance[m*(n-1) + j] < mDistance[m*(n-1) + j]){
            std::cout<<"YES"<<'\n';
            p = buildPath(m*(n-1) + j, m);
            std::cout<<p.length()<<'\n';
            std::cout<<p;
            return;
        }
    }


    for(long long i = 0; i<n; i++){
        if((b[i][0] == '.' || b[i][0] == 'A') && aDistance[m*i] < mDistance[m*i]){
            std::cout<<"YES"<<'\n';
            p = buildPath( m*i, m);
            std::cout<<p.length()<<'\n';
            std::cout<<p;
            return;
        } else if((b[i][m-1] == '.' || b[i][m-1] == 'A')  && aDistance[m*i + (m-1)] < mDistance[m*i + (m-1)]){

            std::cout<<"YES"<<'\n';
            p = buildPath(m*i + (m-1), m);
            std::cout<<p.length()<<'\n';
            std::cout<<p;
            return;
        }
    }

    std::cout<<"NO";


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