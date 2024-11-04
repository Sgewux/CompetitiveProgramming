#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n; ll m;
    cin>>n>>m;
    if(n%2 == 0 && m%2 == 0){
        cout<<"abdullah"<<'\n';
    } else {
        cout<<"hasan"<<'\n';
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