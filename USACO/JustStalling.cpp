#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<ll>b(n);
    for(long long i = 0; i<n; i++) cin>>a[i];
    for(long long i = 0; i<n; i++) cin>>b[i];

    sort(a.begin(), a.end(), greater<ll>());
    sort(b.begin(), b.end());

    ll ans = 1;
    ll used = 0;
    for(long long i = 0; i<n; i++){
        ans *= b.end() - lower_bound(b.begin(), b.end(), a[i]) - used;
        used++;
    }

    cout<<ans;
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