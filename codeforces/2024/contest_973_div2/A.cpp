#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n; ll x; ll y;
    cin>>n>>x>>y;

    x = min(x,y);
    cout<<(n/x + (n%x ? 1 : 0))<<'\n';
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