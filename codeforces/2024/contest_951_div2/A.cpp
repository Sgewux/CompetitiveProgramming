#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll prev = 1e9 + 1;
    cin>>n;
    ll minMax = 1e9 + 1;
    for(long long i = 0; i<n; i++){
        ll a; cin>>a;
        minMax = min(minMax, max(prev, a));
        prev = a;
    }

    cout<<minMax-1<<'\n';
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