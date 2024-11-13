#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll m = 1e9 + 7;
const ll N = 1e5;
const ll M = 100;
ll n; ll b;
vector<ll>a(N);

int dp[N][M+1];

int f(ll i, ll l){
    if(i == n-1){
        if(a[i] == 0){
            int ans = 1;
            if(l > 1) ans++;
            if(l < b) ans++;
            
            return ans;
        } else {
            return (abs(l - a[i]) <= 1 ? 1 : 0);
        }
    } else {

        int &r = dp[i][l];

        if(r == -1){
            if(a[i] == 0){
                if(i == 0){
                    r = 0;
                    for(long long j = 1; j<=b; j++){
                        r += f(i+1, j);
                        if(r >= m) r-=m;
                    }
                } else {
                    r = f(i+1, l);
                    if(l > 1) r += f(i+1, l-1) ;
                    if(r >= m) r-=m;
                    if(l < b) r += + f(i+1, l+1);
                    if(r >= m) r-=m;

                }
            } else {
                if(abs(l - a[i]) <= 1){
                    r = f(i+1, a[i]);
                } else {
                    r = 0;
                }
            }
        }

        return r;

    }
}

void solve(){
    cin>>n>>b;
    for(long long i = 0; i<n; i++) cin>>a[i];
    memset(dp, -1, sizeof(dp[0][0]) * N * (M + 1));

    if(n == 1){
        if( a[0] == 0) {
            cout<<b;
        } else {
            cout<<1;
        }
    } else {
        cout<<f(0,a[0]);
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