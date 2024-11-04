#include <bits/stdc++.h>
#define ll long long

using namespace std;

void pushAndClear(vector<ll>& a, vector<ll>& b){
    ll sum = 0;
    for(long long i = 0; i<a.size(); i++){
        sum += a[i];
        a[i] = 0;
        if(i < b.size()) b[i] += sum;
    }
}

void lazySumRange(vector<ll>& a, ll l, ll r, ll val){
    if(l > r) return;

    a[l] += val;
    a[r+1] -= val;
}

void solve(){
    ll n; ll m;
    ll p = 0;
    cin>>n>>m;
    vector<ll>v(n);
    for(long long i = 0; i<n; i++) cin>>v[i];
    vector<ll>dp(m+1, -1e9);
    vector<ll>a(m+2,0);

    dp[0] = 0;

    for(long long j = 0; j<n; j++){
        ll r = v[j];

        if(r == 0){
            pushAndClear(a,dp);
            for(long long i = m; i>0; i--) dp[i] = max(dp[i], dp[i-1]);
            p++;
        } else if (r > 0){
            lazySumRange(a,r,m,1);
        } else {
            lazySumRange(a,0,p+r,1);
        }
    }

    pushAndClear(a,dp);

    cout<<(*max_element(dp.begin(), dp.end()));
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