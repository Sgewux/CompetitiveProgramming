#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll N = 1e6 + 1;
const ll m = 1e9 + 7;
ll pw[N];

void solve(){
    ll q;
    cin>>q;
    vector<ll>n(q);
    vector<ll>k(q);
    for(long long i = 0; i<q; i++) cin>>n[i];
    for(long long i = 0; i<q; i++) cin>>k[i];

    for(long long i = 0; i<q; i++){
        if(k[i] == 0 || k[i] == n[i]){
            cout<<1<<'\n';
        } else {
            cout<<pw[k[i]]<<'\n';
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t=1;
    pw[0] = 1;

    for(long long i = 1; i<N; i++) pw[i] = (2*pw[i-1]) % m;

    
    while(t--){
        solve();
    }

    return 0;
}