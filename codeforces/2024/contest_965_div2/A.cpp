#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll x;
    ll y;
    ll k;
    cin>>x>>y>>k;

    if(k == 1){
        cout<<x << ' ' <<y <<'\n';
        return;
    }

    for(long long i = 1; i<=k-1; i++){
        cout<<x+i<<' '<<y+i<<'\n';
    }

    cout<<x - (k*(k-1)/2) <<' ' << y - (k*(k-1)/2)<<'\n';
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