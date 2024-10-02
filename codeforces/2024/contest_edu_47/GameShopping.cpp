#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll m;
    cin>>n>>m;
    vector<ll>g(n);
    vector<ll>w(m);

    for(long long i = 0; i<n; i++){
        cin>>g[i];
    }

    for(long long j = 0; j<m; j++){
        cin>>w[j];
    }

    ll i = 0;
    ll j = 0;
    ll ans = 0;
    while(i<n && j<m){
        if(g[i] <= w[j]){
            ans++;
            i++;
            j++;
        } else {
            i++;
        }
    }

    cout<<ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t=1;

    while(t--){
        solve();
    }

    return 0;
}