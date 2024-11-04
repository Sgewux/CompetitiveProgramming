#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n; ll k;
    cin>>n>>k;
    vector<ll>v(n);
    vector<vector<ll>>pa;
    vector<ll> px = {0};
    for(long long i = 0; i<n; i++) cin>>v[i];
    sort(v.begin(), v.end());
    
    ll lastSeen = v[0];
    ll s = 0;
    for(long long i = 0; i<n; i++){
        if(v[i] != lastSeen){

            px.push_back(s);

            if(abs(v[i] - lastSeen) > 1){
                pa.push_back(px);
                px = {0};
            }

            lastSeen = v[i];
            s = 1;
        } else {
            s++;
        }
    }

    if(s){
        px.push_back(s);
        pa.push_back(px);
    }

    ll ans = -1;

    for(auto& p : pa){
        for(ll i = 1; i < p.size() ; i++) p[i] += p[i-1];

        ll l = 1; ll r = min(k, (ll)p.size()-1);
        while(r < p.size()){
            ans = max(ans, p[r] - p[l-1]);
            l++; r++;
        }
    }

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