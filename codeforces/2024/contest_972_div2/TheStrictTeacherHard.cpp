#include <bits/stdc++.h>
#define ll long long

using namespace std;

pair<ll,ll> bounds(vector<ll>& tc, ll t, ll n){
    ll l = 0;
    ll r = n-1;
    ll m;

    while(l < r){
        m = (l+r)/2;
        if(tc[m] > t){
            r = m-1;
        } else {
            l = m+1;
        }
    }

    m = (l+r)/2;

    pair<ll,ll> ans;

    if(tc[m]<t){
        ans.first = tc[m];
        ans.second = tc[m+1];
    } else {
         ans.first = tc[m];
        ans.second = tc[m-1];       
    }

    return ans;
}

void solve(){
    ll n; ll m; ll q;
    cin>>n>>m>>q;
    vector<ll> tc(m);

    for(long long j = 0; j<m; j++){
        cin>>tc[j];
    }

    sort(tc.begin(), tc.end());

    ll currQ;
    for(long long i = 0; i<q; i++){
        cin>>currQ;
        if(m == 1){
            if(currQ < tc[0]){
             cout<<abs(currQ-1) + abs(currQ - tc[0]);
            } else {
                cout<<abs(currQ - n) + abs(currQ - tc[m-1]);
            }
            cout<<'\n';
            continue;
        }

        if(currQ < tc[0]){
            cout<<abs(currQ-1) + abs(currQ - tc[0]);
        } else if(currQ > tc[m-1]){
            cout<<abs(currQ - n) + abs(currQ - tc[m-1]);
        } else {
            pair<ll,ll> tcs = bounds(tc, currQ, m);
            ll t1 = tcs.first;
            ll t2 = tcs.second;

            ll ans  = (abs(abs(currQ-t1) - abs(currQ-t2)))/2;
            ans += min(abs(currQ-t1), abs(currQ-t2));
            cout<< ans;
        }

        cout<<'\n';
    }
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