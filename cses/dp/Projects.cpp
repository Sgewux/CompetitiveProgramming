#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 2e5;
ll dp[N];
ll n;
vector<tuple<ll,ll,ll>> e;

ll bs(ll t){
    ll l = 0;
    ll r = n-1;
    ll m;
    ll ans = -1;

    while(l < r){
        m = (l+r)/2;
        ll bi = get<0>(e[m]);

        if(bi < t){
            l = m+1;
        } else if(bi > t){
            r = m-1;
        } else {
            ans = m;
            r = m-1;
        }
    }
    
    m = (l+r)/2;
    if(ans != -1){
        if(get<0>(e[m]) == t){
            return m;
        } else {
            return ans;
        }
    } else {
        if(get<0>(e[m]) >= t){
            return m;
        } else {
            return m+1;
        }
    }
}

ll f(ll i){
    if(i == n){
        return 0;
    } else {
        ll &r = dp[i];

        if(r == -1){
            ll nextAvailable = bs(get<1>(e[i]) + 1);
            r = f(i+1); // skip
            r = max(r, get<2>(e[i]) + f(nextAvailable)); // take
        }

        return r;
    }
}

void solve(){
    cin>>n;
    for(long long i = 0; i<n; i++) {
        ll a, b, p;
        cin>>a>>b>>p;
        e.push_back(make_tuple(a,b,p));
    }
    sort(e.begin(), e.end());
    memset(dp, -1, sizeof(dp[0]) * N);

    cout<<f(0)<<'\n';

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