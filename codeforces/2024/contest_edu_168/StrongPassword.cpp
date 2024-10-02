#include <bits/stdc++.h>
#define ll long long

void solve(){
    std::string s;
    std::getline(std::cin, s);
    ll n = s.length();
    ll l = -1;
    ll r = -1;

    for(long long i = 0; i<n-1; i++){
        if(s[i] == s[i+1]){
            l = i;
            r = i+1;
            break;
        }
    }

    if(l != -1){
        for(long long i = 0; i<n; i++){
            std::cout<<s[i];
            if(i == l) std::cout<<(s[i] == 'a' ? 'b' : (char)(s[i]-1));
        }
        std::cout<<'\n';
    } else {
        std::cout<<s;
        std::cout<<(s.back() == 'a' ? 'b' : (char)(s.back()-1))<<'\n';
    }

}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;
    std::cin.ignore();
    while(t--){
        solve();
    }

    return 0;
}