#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 1e6;
const ll mod = 1e9 + 7;
ll fac[N+1];
ll inv[N+1];

ll binexpo(ll a, ll b){
    if(b == 0) return 1;
    ll res = binexpo(a, b/2);
    res = (res * res) % mod;
    
    if(b & 1){
        return (res * a) % mod;
    } else {
        return res;
    }
}

ll bSearch(vector<ll>& a, ll n, ll t){
    ll l = 0;
    ll r = n-1;
    ll m;
    ll ans = -1;

    while(l < r){
        m = (l+r)/2;

        if(a[m] < t){
            l = m+1;
        } else if(a[m] > t){
            r = m-1;
        } else {
            ans = max(ans, m);
            l = m+1;
        }
    }

    m = (l+r)/2;

    if(a[m] == t){
        return m;
    } else {
        if(ans != -1){
            return ans;
        } else {
            return (a[m] < t ? m : m-1);
        }
    }
}

ll binom(ll n, ll k){
    if(n < k) {
        return 0;
    } else {
        return (((fac[n] * inv[n-k]) % mod) * inv[k]) % mod;
    }

}

void solve(){
    ll n; ll m; ll k;
    cin>>n>>m>>k;
    vector<ll>a(n);
    
    for(long long i = 0; i<n; i++) cin>>a[i];
    
    sort(a.begin(), a.end());

    ll ans = 0;

    for(long long i = 0; i<n; i++){
        ll r = bSearch(a,n,k+a[i]);
        ans += binom(r-i, m-1);
        if(ans >= mod) ans -= mod;
    }

    cout<<ans<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    fac[0] = 1;
    for(long long i = 1; i<=N; i++) fac[i] = (i * fac[i-1]) % mod;
    inv[N] = binexpo(fac[N],mod-2);
    for(long long i = N-1; i>=0; i--) inv[i] = ((i+1) * inv[i+1]) % mod;

    long long t;
    std::cin>>t;

    while(t--){
        solve();
    }

    return 0;
}