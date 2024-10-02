#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 2e5 + 1;
ll parent[N];
ll sz[N];
ll ans[N];

void make_set(ll v){
    parent[v] = v;
    sz[v] = 1;
}

ll find_set(ll v){
    if(parent[v] == v || parent[v] == -1){
        return parent[v];
    } else {
        parent[v] = find_set(parent[v]);
        return parent[v];
    }
}

void union_sets(ll a, ll b){
    a = find_set(a);
    b = find_set(b);
    if(a!=b){ 
        if(sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> p(n);
    for(long long i = 0; i<N; i++){
        parent[i] = -1;
        sz[i] = 0;
        ans[i] = 0;
    }

    for(long long i = 0; i<n; i++){
        cin>>p[i];
    }

    string color;
    cin.ignore();
    getline(cin, color);

    for(long long i = 0; i<n; i++){

        if(find_set(p[i]) != -1){
            cout<<ans[find_set(p[i])]<<' ';

        } else {

            ll start = p[i];
            ll curr = p[p[i]-1];
            ll cant = 0;
            if(color[p[i]-1] == '0') cant++;
            make_set(start);

            while(curr != start){
                make_set(curr);
                union_sets(curr, start);
                if(color[curr-1] == '0') cant++;
                curr = p[curr-1];
            }

            ans[find_set(start)] = cant;

            cout<<ans[find_set(start)]<<' ';

        }
    }

    cout<<'\n';
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