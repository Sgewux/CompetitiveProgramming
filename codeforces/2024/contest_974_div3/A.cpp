#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n; ll k;
    cin>>n>>k;
    ll ans = 0;
    ll g = 0;

    for(long long i = 0; i<n; i++){
        ll ai; cin>>ai;
        if(ai>=k) g+=ai;
        if(ai == 0){
            if(g > 0){
                ans++;
                g--;
            }
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