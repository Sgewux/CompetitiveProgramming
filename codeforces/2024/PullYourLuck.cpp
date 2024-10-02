#include <bits/stdc++.h>
#define ll long long

void solve(){
    ll n;
    ll x;
    ll p;

    std::cin>>n>>x>>p;
    if(x == 0) x = n;
    for(long long i = 1; i<=std::min(2*n, p); i++){
        if(n-((i*(i+1)/2)%n) == x){
            std::cout<<"YES"<<'\n';
            return;
        }
    }

    std::cout<<"NO"<<'\n';
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