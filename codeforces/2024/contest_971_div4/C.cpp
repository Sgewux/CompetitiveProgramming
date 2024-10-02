#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll x; ll y; ll k;
    cin>>x>>y>>k;

    ll xmoves = (x % k == 0 ? x/k : (x/k) + 1);
    ll ymoves = (y % k == 0 ? y/k : (y/k) + 1);

    if(ymoves > xmoves){
        cout<<2*ymoves<<'\n';
    } else if(xmoves > ymoves){
        cout<<2*xmoves - 1<<'\n';
    } else {
        cout<<2*xmoves<<'\n';
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