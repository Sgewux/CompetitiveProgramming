#include <bits/stdc++.h>
#define ll long long

void solve(){
    ll n;
    std::cin>>n;
    std::vector<ll>a(n);

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
    }

    ll max = -1;

    for(long long i = 0; i<n; i++){
        if(i%2 == 0){
            max = std::max(max, a[i]);
        }
    }

    std::cout<<max<<'\n';
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