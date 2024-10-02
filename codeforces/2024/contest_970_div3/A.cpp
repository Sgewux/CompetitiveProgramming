#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll a; ll b;
    cin>>a>>b;
    b %= 2;
    a -= (2*b);

    cout<<(a>=0 && a%2 == 0 ? "YES" : "NO");
    cout<<'\n';
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