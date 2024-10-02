#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll N = 3001;
ll memo[N][N];
ll a[N];

ll f(ll l, ll r){
    if(l == r){
        return a[l];
    } else {
        ll &m = memo[l][r];
        if(m == -1){
            m = max(a[l] - f(l+1,r), a[r] - f(l, r-1));
        }
        
        return m;
    }
}

void solve(){
    ll n;
    cin>>n;
    for(ll i = 0; i<n; i++) cin>>a[i];
    memset(memo, -1,  sizeof(memo[0][0]) * N * N);
    
    cout<<f(0,n-1);
    
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