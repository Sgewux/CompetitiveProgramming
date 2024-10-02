#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<ll> p(n+1, 0);

    for(long long i = 1; i<=n; i++){
        cin>>p[i];
        p[i] += p[i-1];
    }

    cout<<(p[n] - p[n-1]) - ((p[n-1] - 2*p[n-2]))<<'\n';
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