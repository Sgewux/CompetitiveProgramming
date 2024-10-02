#include <bits/stdc++.h>
#define ll long long

const ll mod = 1e9 + 7;

using namespace std;

ll mul(ll a, ll b){
    return ((a % mod)*(b % mod)) % mod;
}

ll sum(ll a, ll b){
    return ((a + b) >= mod ? (a+b)-mod : (a+b));
}

ll binpow(ll a, ll b){
    if(b == 0) return 1;
    ll res = binpow(a,b/2);

    if(b & 1){
        return mul(mul(res,res), a);
    } else {
        return mul(res,res);
    }
}

void solve(){
    ll n;
    cin>>n;
    vector<ll>pf(n+1,0);
    vector<ll>v(n);

    for(long long i = 0; i<n; i++){
        cin>>v[i];
        pf[i+1] = v[i] + pf[i];
    }

    ll p = 0;

    for(long long i = 0; i<n; i++){
        p = sum(p, mul(v[i], pf[n] - pf[i+1]));
    }

    cout<< mul(p,binpow(n*(n-1)/2, mod-2))<<'\n';
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