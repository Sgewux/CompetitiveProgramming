#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    string s;
    string t;
    ll ans = 0;
    getline(cin, s);
    getline(cin, t);

    ll p = 0;
    ll i = 0;
    while(i < s.length() && i < t.length()){
        if(s[i] != t[i]) break;
        p++;
        i++;
    }

    if(p) ans += p + 1;
    ans += (s.length() - p) + (t.length() - p);
    cout<<ans<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;
    cin.ignore();
    while(t--){
        solve();
    }

    return 0;
}