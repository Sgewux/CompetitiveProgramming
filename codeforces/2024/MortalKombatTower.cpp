#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

const ll N = 2e5;
ll dp[N+1][2];
vector<ll>a(N);
ll n;

ll f(ll i, ll p){

    if(i == n-1){
        if(p){
            return 0;
        } else {
            return a[i];
        }
    } else {
        ll &r = dp[i][p];
        if(r == -1){
            if(p){
                r = f(i+1, !p);
                if(i == n-2){
                    r = 0;
                } else {
                    r = min(r, f(i+2, !p));
                }
            } else {
                r = a[i] + f(i+1, !p);
                if(i == n-2) {
                    r = min(r, a[i] + a[i+1]);
                } else {
                    r = min(r, a[i] + a[i+1] + f(i+2, !p));
                }
            }
        }
        
        return r;
    }
}

void solve(){
    cin>>n;
    for(ll i = 0; i<n; i++){
        cin>>a[i];
        dp[i][0] = -1;
        dp[i][1] = -1;
    }
    
    cout<<f(0,0)<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    
    ll t;
    cin>>t;
    
    while(t--){
        solve();
    }
    
    return 0;
}