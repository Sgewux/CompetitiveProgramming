#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll m;
    cin>>n>>m;

    if(n-1 <= m && m <= n*(n-1)/2){
        vector<pair<ll,ll>> edges;
        for(long long i = 1; i<n; i++){
            edges.push_back({i,i+1});
        }
        
        m-=(n-1);
        ll i = 1;
        ll j = 2;
        while(m > 0 && i < n-1){
            if(i + j > n){
                i = i+1;
                j = 2;
            } else {
                if(gcd(i, i+j) == 1) {
                    m--;
                    edges.push_back({i,i+j});
                }

                j++;
            }
        }

        if(m != 0){
            cout<<"Impossible";
        } else {
            cout<<"Possible"<<'\n';
            for(auto& p : edges){
                cout<<p.first <<' '<<p.second<<'\n';
            }
        }

    } else {
        cout<<"Impossible";
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