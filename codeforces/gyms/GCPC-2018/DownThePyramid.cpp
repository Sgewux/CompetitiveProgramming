#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n+1);
    for(long long i = 0; i<n; i++) cin>>a[i];
    b[0] = 0;
    ll l = 0;
    ll r = 1e9;
    for(long long i = 1; i<=n; i++){
        b[i] = a[i-1] - b[i-1];
        if(i & 1){
            r = min(r, b[i]);
        } else {
            l = min(l, b[i]);
        }
    }

    cout<<max((ll)0, l + r + 1);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t=1;

    while(t--){
        solve();
    }

    return 0;
}