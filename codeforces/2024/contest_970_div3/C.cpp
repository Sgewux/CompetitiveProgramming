#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll l; ll r;
    cin>>l>>r;
    ll g = 0;
    ll i = 1;
    ll ans = 0;
    while(l + g <= r){
        ans++;
        g += i;
        i++;
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