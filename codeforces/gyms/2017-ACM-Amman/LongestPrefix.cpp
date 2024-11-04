#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    string a; string b;
    ll ans = 0;
    cin>>a>>b;
    map<char,ll> m;
    for(auto& c : b) m[c]++;

    for(auto& c : a){
        if(m[c] > 0){
            ans++; m[c]--;
        } else {
            break;
        }
    }

    cout<<ans<<'\n';
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