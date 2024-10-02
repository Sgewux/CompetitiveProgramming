#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 2e5 + 1;
bool visited[N];
ll disA[N];
ll disB[N];
ll disI[N];

vector<ll> adj[N];
vector<ll> adjI[N];

void clearVisited(){
    for(long long i = 0; i<N; i++) visited[i] = false;
}

void bfs(ll node, ll dis[N], vector<ll> ad[N]){
    dis[node] = 0;
    visited[node] = true;
    queue<ll> q;
    q.push(node);

    while(!q.empty()){
        ll curr = q.front(); q.pop();
        for(auto& n : ad[curr]){
            if(!visited[n]){
                dis[n] = dis[curr] + 1;
                visited[n] = true;
                q.push(n);
            }
        }
    }
}

void solve(){
    ll n; ll m; ll a; ll b;
    cin>>n>>m>>a>>b;
    
    for(long long i = 0; i<n+1; i++){
        disA[i] = 1e9;
        disB[i] = 1e9;
        disI[i] = 1e9;
    }

    for(long long j = 0; j<m; j++){
        ll x; ll y;
        cin>>x>>y;
        adj[x].push_back(y);
        adjI[y].push_back(x);
    }

    clearVisited();
    bfs(0,disI,adj);
    clearVisited();
    bfs(a,disA,adjI);
    clearVisited();
    bfs(b,disB,adjI);

    ll ans = 1e9;

    for(long long i = 0; i<=n; i++){
        ans = min(ans, disI[i] + disA[i] + disB[i]);
    }

    cout<<ans;
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