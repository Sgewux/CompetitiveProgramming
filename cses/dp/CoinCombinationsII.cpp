#include <bits/stdc++.h>
#define ll long long

using namespace std;
const int N = 101;
const int X = 1e6 + 1;
const int m = 1e9 + 7;

int dp[X];

void solve(){
    ll n; ll x;
    cin>>n>>x;
    vector<int>v(n+1,0);
    for(int i = 1; i<=n; i++) cin>>v[i];
    sort(v.begin(), v.end());

    memset(dp, 0, sizeof(dp[0]) * X);

    for(int i = 1; i<=n; i++){
        int ai = v[i];
        for(int j = 1; j<=x; j++){
            int &r = dp[j];

            if(j > ai){
                r += dp[j-ai];
            } else if(ai == j){
                r += 1;
            }

            if(r >= m) r -= m;
        }
    }

    cout<<dp[x];
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t=1;

    while(t--){
        solve();
    }

    return 0;
}