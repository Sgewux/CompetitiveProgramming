#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
const ll N = 500;
ll dp[N+1][N+1];
 
ll f(ll a, ll b){
    if(a == b){
        return 0;
    } else {
        ll &r = dp[a][b];
        ll &x = dp[b][a];
        
        if(r == -1 && x == -1){
            r = 1e9;
            for(ll i = 1; i<=500; i++) {
                if(i<=b-1) r = min(r, 1 + f(a,i) + f(a,b-i));
                if(i<=a-1) r = min(r, 1 + f(i,b) + f(a-i,b));
            }
        }
        
        return (r != -1 ? r : x);
    }
}
 
void solve(){
    ll a; ll b;
    cin>>a>>b;
    memset(dp, -1, sizeof(dp[0][0])*(N+1)*(N+1));
    
    cout<<f(a,b);
}
 
int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
 
    long long t = 1;
 
    while(t--){
        solve();
    }
 
    return 0;
}