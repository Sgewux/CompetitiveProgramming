#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
void solve(){
    ll n;
    cin>>n;
    vector<ll>h(n);
    vector<ll>v(n);
    for(long long i = 0; i<n; i++) cin>>h[i];
    for(long long i = 0; i<n; i++) cin>>v[i];
 
    ll ans = v[0] - h[0];
    if(h[0] > v[0]){
        cout<<0<<'\n';
        return;
    }

    for(long long i = 1; i<n; i++){
        if((h[i] + ans) > v[i]){
            cout<<ans<<'\n';
            return;
        } else if((h[i] + ans) < v[i]){
            cout<<ans+1<<'\n';
            return;
        }
    }
 
    cout<<ans<<'\n';
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