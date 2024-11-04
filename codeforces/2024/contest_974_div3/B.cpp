#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n; ll k;
    cin>>n>>k;
    ll l = n-k;
    ll sum = (n*(n+1)/2) - (l*(l+1)/2);

    if(k >= n){
        cout<<(n*(n+1)/2 & 1 ? "NO" : "YES")<<'\n';
    } else {
        cout<<(sum & 1 ? "NO" : "YES")<<'\n';
    }
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