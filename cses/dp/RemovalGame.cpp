#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const ll N = 5000;
vector<ll>a(N);
vector<ll>pf(N+1,0);
ll dp[N+1][N+1][2];
 
ll f(ll l, ll r, int p){
    if(l == r){
        if(!p){
            return a[l-1];
        } else {
            return 0;
        }
    } else {
        ll &an = dp[l][r][p];
 
        if(an == -1){
            if(!p){
                an = max(a[l-1] + f(l+1, r, !p), a[r-1] + f(l, r-1, !p));
            } else {
                ll a1 = a[l-1] + ((pf[r] - pf[l]) - f(l+1, r, !p));
                ll a2 = a[r-1] + ((pf[r-1] - pf[l-1]) - f(l, r-1, !p));
                if(a1 > a2){
                    an = f(l+1, r, !p);
                } else {
                    an = f(l, r-1, !p);
                }
            }
        }
 
        return an;
    }
}
 
void solve() {
    ll n; cin>>n;
 
    for(ll i = 0; i<n; i++) cin>>a[i];
    for(ll i = 1; i <=n; i++) pf[i] = pf[i-1] + a[i-1];
 
    memset(dp, -1, sizeof(dp[0][0][0]) * (N+1) * (N+1) * (2));
 
    cout<<f(1,n,0);
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 
    solve();
}