#include <bits/stdc++.h>
#define ll long long
#define ld long double

using namespace std;

const ll T = 5e6;
int dp[T+1][2];
int t, a, b;

int f(int cf, int p){
    if(cf + min(a,b) > t){
        if(!p){
            return cf;
        } else {
            return max(cf, f(cf/2, 0));
        }
    } else {
        int &r = dp[cf][p];
        
        if(r == -1){
            if(cf + a <= t) r = max(r,f(cf+a, p));
            if(cf + b <= t) r = max(r,f(cf+b, p));
            if(p) r = max(r, f(cf/2, !p));
        }
        
        return r;
    }
}

void solve(){
    cin>>t>>a>>b;
    memset(dp, -1, sizeof(dp[0][0]) * (T+1)  * 2);
    cout<<f(0,1);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    
    freopen("feast.in", "r", stdin);
    freopen("feast.out", "w", stdout);

    solve();
    
    return 0;
}