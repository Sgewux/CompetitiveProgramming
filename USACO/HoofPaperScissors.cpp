#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 1e5;
const ll K = 20;
char mv[] = {'H', 'P', 'S'};
vector<char> v(N);
ll n;

ll dp[N][3][K+1];

ll f(ll i, ll m, ll k){
    if(i == n-1){
        return (mv[m] == v[i] ? 1 : 0);
    } else {
        ll &r = dp[i][m][k];

        if(r == -1){
            r = (mv[m] == v[i] ? 1 : 0) + f(i+1, m, k);
            
            if(k){
                for(long long j = 0; j<3; j++){
                    if(j != m) r = max(r, (mv[m] == v[i] ? 1 : 0) + f(i+1, j, k-1));
                }
            }
        }

        return r;
    }
}

void solve(){
    ll k;
    cin>>n>>k;
    memset(dp, -1, sizeof(dp[0][0][0]) * N * 3 * (K+1));
    for(long long i = 0; i<n; i++) cin>>v[i];

    ll ans = 0;
    for(long long i = 0; i<3; i++) ans = max(ans, f(0,i,k));

    cout<<ans<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::freopen("hps.in", "r", stdin);
    std::freopen("hps.out", "w", stdout);

    long long t=1;

    while(t--){
        solve();
    }

    return 0;
}