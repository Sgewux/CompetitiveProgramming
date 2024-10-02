#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
const ll N = 2e5 + 1;
int parent[N];
int sz[N];
 
void make_set(ll v){
    parent[v] = v;
    sz[v] = 1;
}
 
ll find_set(ll v){
    if(parent[v] == v){
        return v;
    } else {
        parent[v] = find_set(parent[v]);
        return parent[v];
    }
}
 
void union_set(ll a, ll b){
    a = find_set(a);
    b = find_set(b);
    if(a != b){
        if(sz[a] < sz[b]) swap(a,b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}
 
void solve(){
    ll n; ll m;
    ll ans = 0;
    cin>>n>>m;
    priority_queue<tuple<ll,ll,ll>> q;
    for(long long i = 1; i<=n; i++) make_set(i);
 
    for(long long j = 0; j<m; j++){
        ll a; ll b; ll c;
        cin>>a>>b>>c;
        q.push({-c,a,b});
    }
 
    while(!q.empty()){
        tuple<ll,ll,ll> t = q.top(); 
        q.pop();
        if(find_set(get<1>(t)) != find_set(get<2>(t))){
            ans -= get<0>(t);
            union_set(get<1>(t), get<2>(t));
        }
    }
 
    bool connected = true;
    ll f = find_set(1);
 
    for(long long i = 2; i<=n; i++){
        connected = (f == find_set(i));
    }
 
    cout<<(connected ? to_string(ans) : "IMPOSSIBLE");
    
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