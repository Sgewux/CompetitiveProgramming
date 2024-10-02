#include <bits/stdc++.h>
#define ll long long

ll lw(ll x){
    ll l = 0;
    ll r = 30;
    ll m;

    while(l < r){
        m = (l+r)/2;

        if(m*(m+1)/2 > x){
            r = m-1;
        } else if(m*(m+1)/2 < x){
            l = m+1;
        } else {
            return m;
        }
    }

    m = (l+r)/2;
    if(m*(m+1)/2 <= x){
        return m;
    } else {
        return m-1;
    }
}

void solve(){
    ll n;
    ll k;
    std::cin>>n>>k;
    ll ones = lw(k);
    ll diff = k-(ones*(ones+1)/2);

    for(long long i = 0; i<diff; i++){
        std::cout<<2<<' ';
    }

    for(long long i = 0; i<ones-diff; i++){
        std::cout<<1<<' ';
    }

    if(k != n*(n+1)/2){
        std::cout<<(-1)*(ones-diff) - 1<<' ';

        for(long long i = 0; i<n-ones-1; i++){
            std::cout<<(ll)-1e3<<' ';
        }
    }

    std::cout<<'\n';
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