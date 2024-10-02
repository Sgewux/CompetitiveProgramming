#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    vector<pair<ll,ll>>r;
    for(long long i = 0; i<2; i++){
        ll a; ll b;
        cin>>a>>b;
        r.push_back({a,b});
    }

    sort(r.begin(), r.end());

    if(r[0].second < r[1].first){
        cout<<1<<'\n';
    } else if (r[1].second >= r[0].second){
        ll ans = abs(r[1].first - r[0].second);
        if(r[0].second != r[1].second) ans++;
        if(r[0].first != r[1].first) ans++;
        cout<<ans<<'\n';
    } else {
        cout<<abs(r[1].second - r[1].first) + 2<<'\n';
    }
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