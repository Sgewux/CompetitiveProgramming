#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll a;
    ll b;
    cin>>a>>b;

    ll c = a;
    ll ans = (c-a) + (b-c);
    while(c <= b){
        ans = min(ans, (c-a) + (b-c));
        c++;
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