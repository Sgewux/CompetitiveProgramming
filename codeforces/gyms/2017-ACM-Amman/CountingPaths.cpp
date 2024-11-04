#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll m = 1e9 + 7;
const ll N = 1e5;

ll fac[N+1];
ll inv[N+1];

ll binexpo(ll a, ll b){
    if(b == 0) return 1;
    ll res = binexpo(a, b/2);
    res = ((res % m) * (res % m)) % m;
    if(b & 1){
        res = ((res % m) * (a % m)) % m;
    }

    return res;
}


void solve(){
    ll a; ll b;
    cin>>a>>b;
    
    if(b == 0){
        cout<<2<<'\n';
    } else {
        ll ans = (((fac[a-1] * inv[b]) % m) * inv[a-1-b]) % m;
        ans = 2 * ans % m;
        cout<<ans<<'\n';
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;
    fac[0] = 1;
    for(long long i = 1; i<=N; i++) fac[i] = (fac[i-1] * i) % m;
    inv[N] = binexpo(fac[N],m-2);
    for(long long i = N; i>=1; i--) inv[i-1] = inv[i] * i % m;
    

    while(t--){
        solve();
    }

    return 0;
}