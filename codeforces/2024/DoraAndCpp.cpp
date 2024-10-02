#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n; ll a; ll b;
    cin>>n>>a>>b;
    vector<ll> v(n);
    ll d = gcd(a,b);

    for(long long i = 0; i<n; i++){
        cin>>v[i];
        v[i] %= d;
    }

    sort(v.begin(), v.end());

    ll ans = v[n-1] - v[0];

    for(long long i = 1; i<n; i++) ans = min(ans, v[i-1] + d - v[i]);

    cout<<ans<<'\n';
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