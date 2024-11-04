#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 1e7;
const ll m = 1e9 + 7;

ll fac[N+1];
ll inv[N+1];

ll binexpo(ll a, ll b){
    if(b == 0) return 1;
    ll res = binexpo(a,b/2);
    res = (res * res)  % m;

    if(b & 1){
        return (res * a) % m;
    } else {
        return res;
    }
}

ll binom(ll n, ll k){
    return (((fac[n] * inv[k]) % m) * inv[n-k]) % m;
}

void solve(){
    ll n; ll m;
    cin>>n>>m;
    cout << binom(m + n - 1, n-1);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t=1;
    fac[0] = 1;
    for(long long i = 1; i<=N; i++) fac[i] = (fac[i-1] * i) % m;
    inv[N] = binexpo(fac[N], m-2);
    for(long long i = N-1; i>=0; i--) inv[i] = (inv[i+1] * (i+1)) % m;

    while(t--){
        solve();
    }

    return 0;
}