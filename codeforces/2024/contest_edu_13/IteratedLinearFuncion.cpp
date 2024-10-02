#include <bits/stdc++.h>
#define ll long long
 
ll mod = 1e9 + 7;
 
using namespace std;
 
ll mul(ll a, ll b){

    return ((a%mod)*(b%mod)) % mod;
}
 
ll binpow(ll a, ll b){
    if(b == 0){
        return 1;
    } else {
        ll res = binpow(a,b/2);
        if(b%2 == 0){
            return mul(res,res);
        } else {
            return mul(mul(res, res),a);
        }
    }
}
 
void solve(){
    ll A; ll B; ll n; ll x;
    cin>>A>>B>>n>>x;
 
    ll ans1 = mul(binpow(A,n), x);
    ll ans2;
    if(A != 1){
        ans2 = mul(B, mul((binpow(A,n) - 1 + mod) % mod, binpow(A-1, mod-2)));
    } else {
        ans2 = mul(B,n);
    }
    ll ans = ans1 + ans2;
    if(ans >= mod) ans-=mod;
 
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