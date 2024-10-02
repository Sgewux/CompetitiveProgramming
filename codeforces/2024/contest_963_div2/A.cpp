#include <bits/stdc++.h>
#define ll long long

void solve(){
    ll n;
    std::cin>>n;
    std::cin.ignore();
    std::string s;
    std::getline(std::cin, s);

    std::map<char,ll> m;
    char curr;

    for(auto& curr : s){
       if(curr != '?')m[curr]++;
    }

    ll ans = 0;

    for(auto& c : m){
        ans += std::min(n,c.second);
    }

    std::cout<<ans<<'\n';
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