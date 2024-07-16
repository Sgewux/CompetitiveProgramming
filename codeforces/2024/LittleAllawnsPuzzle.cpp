#include <bits/stdc++.h>

const int N = 1e6;
std::set<int> adj[N];
bool visited[N] = {false};
int distance[N];
long long M = 1e9 + 7;

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

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return (res * res * a)%M;
    else
        return (res * res)%M;
}

void solve(){
    long long n;
    std::cin>>n;

    std::vector<long long>a(n);
    std::vector<long long>b(n);

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
        visited[a[i]] = false;
        adj[a[i]].clear();
    }

    for(long long i = 0; i<n; i++){
        std::cin>>b[i];
        adj[a[i]].insert(b[i]);
        adj[b[i]].insert(a[i]);
    }
    
    long long x = 0;
    for(long long i = 0; i<n; i++){
        if(!visited[a[i]]){
            x++;
            dfs(a[i]);
        }
    }
    std::cout<<binpow(2,x)<<'\n';

}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;

    while(t--){
        solve();
    }

    return 0;
}