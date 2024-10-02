#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 101;
const ll W = 1e5 + 1;

ll memo[N][W];

void solve(){
    ll n; ll w;
    cin>>n>>w;
    vector<pair<ll,ll>> v(n);
    for(ll i = 0; i < n; i++) cin>>v[i].first>>v[i].second;
    
    memset(memo, 0, sizeof(memo[0][0]) * N * W);
    
    for(ll i = 1; i <= n; i++){
        ll wi; ll vi;
        wi = v[i-1].first;
        vi = v[i-1].second;
        
        for(ll j = 1; j<=w; j++){
            if(j >= wi){
                memo[i][j] = max(memo[i-1][j], memo[i-1][j-wi] + vi);
            } else {
                memo[i][j] = memo[i-1][j];
            }
        }
    }
    
    cout<<memo[n][w];
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