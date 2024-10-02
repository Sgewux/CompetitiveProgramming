#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<ll>ones;
    vector<ll>zeros;
    set<ll> so;
    set<ll> sz;

    for(long long i = 0; i<n; i++){
        ll xi; ll yi;
        cin>>xi>>yi;

        if(yi == 0){
            zeros.push_back(xi);
            sz.insert(xi);
        } else {
            ones.push_back(xi);
            so.insert(xi);
        }
    }

    sort(ones.begin(), ones.end());
    sort(zeros.begin(), zeros.end());

    ll ans = 0;

    for(long long i = 0; i<zeros.size(); i++){
        if(so.count(zeros[i])) ans += (zeros.size()-1);

        if(so.count(zeros[i] - 1) && so.count(zeros[i] + 1)) ans++;
    }

    for(long long i = 0; i<ones.size(); i++){
        if(sz.count(ones[i])) ans += (ones.size()-1);

        if(sz.count(ones[i] - 1) && sz.count(ones[i] + 1)) ans++;
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