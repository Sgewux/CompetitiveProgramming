#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    map<ll,ll> m;

    for(long long i = 0; i<n; i++){
        string s; ll f;
        cin>>s>>f;
        m[f]++;
    }

    ll ans;
    ll freq = -1;

    for(auto& ch : m){
        if(ch.second > freq) {
            ans = ch.first;
            freq = ch.second;
        } else if(ch.second == freq){
            ans = min(ans, ch.first);
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