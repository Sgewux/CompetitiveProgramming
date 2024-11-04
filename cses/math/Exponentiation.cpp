#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll m = 1e9 + 7;

ll binexpo(ll a, ll b){
    if(b == 0) return 1;
    ll res = binexpo(a,b/2);
    res = (res * res)  % m;

    if(b & 1){
        return (res * a) % m;
    } else {
        return res;
    }
}


void solve(){
    ll n;
    cin>>n;

    while(n--){
        ll a; ll b;
        cin>>a>>b;
        cout<<binexpo(a,b)<<'\n';
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