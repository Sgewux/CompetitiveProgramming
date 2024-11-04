#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n; ll k;
    cin>>n>>k;
    vector<ll> pr(k+1, 0);
    for(long long i = 0; i<k; i++){
        ll b; ll c;
        cin>>b>>c;
        pr[b] += c;
    }

    sort(pr.begin(), pr.end(), greater<ll>());

    ll ans = 0;

    for(long long i = 0; i<min(n,k); i++){
        ans += pr[i];
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