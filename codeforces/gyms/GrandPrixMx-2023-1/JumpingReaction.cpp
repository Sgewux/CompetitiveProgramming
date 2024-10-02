#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll mod = 1e9 + 7;

void solve(){
    ll n;
    ll q;
    cin>>n>>q;
    vector<ll>a(n);
    vector<ll>s(n);
    vector<ll>ans(n);

    for(long long i = 0; i<n; i++){
        cin>>a[i];
        if(i > 0){
            s[i] = (s[i-1] + a[i]) % mod;
            ans[i] = (ans[i-1] + (a[i]*s[i-1]) % mod) % mod;
        } else {
            s[i] = a[i];
            ans[i] = 0;
        }
    }
    
    ll r;
    ll l;
    while(q--){
        cin>>l>>r;

        if(l == r){
            cout<<a[l-1]%mod<<'\n';
        } else if(l == 1){
            cout<<ans[r-1]%mod<<'\n';
        } else {
            ll qans = (((ans[r-1] - ans[l-2] + mod) % mod) - (s[l-2]%mod * ((s[r-1] - s[l-2] + mod)%mod))%mod + mod ) % mod;
            cout<<qans<<'\n';
        }
    }
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