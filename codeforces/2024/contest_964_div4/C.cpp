#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll s;
    ll m;
    ll li;
    ll ri;
    ll rprev = 0;
    cin>>n>>s>>m;
    bool yes = false;

    for(long long i = 0; i<n; i++){
        cin>>li>>ri;
        if(li - rprev >= s){
            yes = true;
        }
        rprev = ri;
    }

    if(m-rprev >= s) yes = true;

    cout<<(yes ? "YES" : "NO")<<'\n';


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