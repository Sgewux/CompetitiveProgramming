#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll k;
    cin>>n>>k;
    
    cout<<(n/k + 1)*k;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t =1;

    while(t--){
        solve();
    }

    return 0;
}