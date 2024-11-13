#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
void solve(){
    string a; string b;
    ll n; ll m;
    cin>>a>>b;
    n = a.length();
    m = b.length();
 
    int dp[n + 1][ m + 1];
    memset(dp, 0, sizeof(dp[0][0]) * (n+1) * (m+1));
 
    for(long long i = 0; i<=n; i++){
        for(long long j = 0; j<=m; j++){
            int &r = dp[i][j];
            r = max(i,j);
            if(i == 0 || j == 0) continue;

            if(i == 1 && j == 1){
                r = (a[0] == b[0] ? 0 : 1);
            }
            if(i > 0) r = min(r, dp[i-1][j] + 1); //skip i-th
            if(j > 0) r = min(r, dp[i][j-1] + 1); //skip j-th
            if(i > 0 && j > 0) r = min(r, dp[i-1][j-1] + 1); //change value
            
            if((i > 0 && j > 0) && (a[i-1] == b[j-1])) r = min(r, dp[i-1][j-1]); //nothin to do
        }
    }

 
    cout<<dp[n][m];
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