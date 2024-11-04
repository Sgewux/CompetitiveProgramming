#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<vector<int>>m(105, vector<int>(105,0));
    for(long long i = 0; i<n; i++){
        ll w; ll h;
        cin>>w>>h;
        for(long long j = 1; j<=h; j++){
            for(long long k = 1; k<=w; k++){
                m[j][k] = 1;
            }
        }
    }

    ll ans = 0;
    for(long long i = 1; i<=100; i++){
        for(long long j = 1; j<=100; j++){
            if(m[i][j] == 1){
                ans += (m[i-1][j] == 0);
                ans += (m[i+1][j] == 0);
                ans += (m[i][j+1] == 0);
                ans += (m[i][j-1] == 0);
            }
        }
    }
    cout<<ans<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;

    while(t--){
        solve();
    }

    return 0;
}