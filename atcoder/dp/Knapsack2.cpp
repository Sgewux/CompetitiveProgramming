#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 100;
const ll V = 1e3;
ll n; ll w;
vector<pair<ll,ll>> v(N, {0,0});

ll memo[N][N*V + 1];

ll f(ll i, ll wanted){
    if(i == n){
        return (wanted == 0 ? 0 : 1e9 + 1);
    }
    
    ll &r = memo[i][wanted];
    if(r!=-1) return r;
    r = f(i+1, wanted);
    if(v[i].second <= wanted){
        r = min(r, f(i+1, wanted - v[i].second) + v[i].first);
    }

    return r;
}

void solve(){
    cin>>n>>w;
    for(ll i = 0; i < n; i++) cin>>v[i].first>>v[i].second;
    memset(memo, -1, sizeof(memo[0][0]) * N * (N * V + 1));
    
    ll ans = 0;
    
    for(ll i = 1; i <= 1e5; i++){
        if(f(0,i) <= w) ans = i;
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