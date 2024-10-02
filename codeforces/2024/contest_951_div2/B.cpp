#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll x; ll y;
    cin>>x>>y;
    ll z = x ^ y;
    ll ans = 1;

    if(z & 1){
        cout<< 1 <<'\n';
        return;
    }

    while(!(z & 1)){
        ans *= 2;
        z = z>>1;
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