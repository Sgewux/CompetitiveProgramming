#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll e = 0;
    ll o = 0;
    vector<ll> ae;
    ll maxE = -1;
    ll maxO = -1;
    ll curr;
    cin>>n;

    for(long long i = 0; i<n; i++){
        cin>>curr;
        if(curr%2 == 0){
            e++;
            ae.push_back(curr);
            maxE = max(maxE, curr);
        } else {
            o++;
            maxO = max(maxO, curr);
        }
    }

    sort(ae.begin(), ae.end());

    if(e && o){
        ll toadd = 0;
        if(maxE > maxO) {
            ll c = maxO;
            toadd = 1;

            for(long long i = 0; i<e; i++){
                if(ae[i] < c){
                    c+=ae[i];
                }
            }

            if(c > maxE) toadd=0;
        }
        cout<<e + toadd<<'\n';
    } else {
        cout<<0<<'\n';
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