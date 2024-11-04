#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<pair<ll,ll>>a;
    vector<ll>dp(n+1, 0);
    for(long long i = 1; i<=n; i++) {
        ll ai; cin>>ai;
        if(i > 1){
            a.push_back({ai - (n - (i-1)), i-1});
        }
    }

    map<ll,ll> mp;

    sort(a.begin(), a.end());

    for(long long i = 0; i<n-1; i++) mp[a[i].first] = i;

    for(long long i = n-2; i>=0; i--){

        ll &r = dp[mp[a[i].first]];
        if(mp.count(a[i].first + a[i].second)){
            r = max(r, a[i].second  + dp[mp[a[i].first + a[i].second]]);
        } else {
            r = max(r, a[i].second);
        }
        
    }

    cout<<n + (mp.count(0) ? dp[mp[0]] : 0)<<'\n';
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