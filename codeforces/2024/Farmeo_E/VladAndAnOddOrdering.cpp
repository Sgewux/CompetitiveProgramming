#include <bits/stdc++.h>
#define ll long long

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return (res * res * a);
    else
        return (res * res);
}

void solve(){
    ll n;
    ll k;
    std::cin>>n>>k;

    ll i = 1;
    ll j = 0;
    ll l = 1;
    ll r = (n%2 == 0 ? n/2 : (ll)(n/2) + 1);

    while(k > r){
        i++;
        j++;
        l = r+1;
        r += (n-binpow(2,j))/binpow(2,i) + 1;
    }

    std::cout<< binpow(2,i)*(k-l) + binpow(2,j)<<'\n';
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