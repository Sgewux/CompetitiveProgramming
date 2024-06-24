#include <bits/stdc++.h>

void solve(){
    std::string s;
    std::getline(std::cin, s);

    std::swap(s[0], s[4]);

    std::cout<<s<<'\n';

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