#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll m;
    ll k;
    cin>>n>>m>>k;
    vector<ll> a(n);
    for(long long i = 0; i<n; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end());
    ll ans = 0;
    ll p = 0;
    for(long long i = 1; i<=(k%m == 0 ? k/m : (k/m)+1); i++){
        if(i <= k/m){
            ans += m*a[i-1];
            ans += m*p;
            p += m;
        } else {
            ans += (k%m)*a[i-1];
            ans += (k%m)*p;
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