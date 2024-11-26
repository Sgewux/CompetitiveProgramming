#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll m = 1e9 + 7;
int dp[21][3000000];
int n;
vector<vector<int>> v(21, vector<int>(21,0));

int f(int i, int mask){
    if(i == n-1){
        for(long long l = 0; l<n; l++){
            if(!(mask & (1 << l)) && v[i][n-1-l]) return 1;
        }

        return 0;

    } else {
        int &r = dp[i][mask];

        if(r == -1){
            r = 0;
            for(long long l = 0; l<n; l++){
                if(!(mask & (1 << l)) && v[i][n-1-l]){
                    r += f(i+1, mask | (1 << l));
                    if(r >= m) r-= m;
                }
            }
        }

        return r;
    }
}

void solve(){
    cin>>n;
    memset(dp, -1, sizeof(dp[0][0]) * 21 * 3000000);
    for(long long i = 0; i<n; i++){
        for(long long j = 0; j<n; j++) cin>>v[i][j];
    }

    cout<<f(0,0);

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