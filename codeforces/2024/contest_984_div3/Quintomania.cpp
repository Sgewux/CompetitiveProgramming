#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(long long i = 0; i<n; i++){
        cin>>a[i];
    }
    bool t = true;
    for(long long i = 0; i<n-1; i++){
        ll ab= abs(a[i] - a[i+1]);
        t = t & (ab == 5 || ab == 7);
    }

    cout<<(t ? "YES" : "NO")<<'\n';
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