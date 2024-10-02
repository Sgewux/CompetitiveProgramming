#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll a;
    ll b;
    ll p;
    ll q;
    cin>>n>>a>>b>>p>>q;

    if(p > q){
        cout<< p*(n/a) + q*(n/b - n/lcm(a,b));
    } else {
        cout<< q*(n/b) + p*(n/a - n/lcm(a,b));
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