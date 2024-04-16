#include <bits/stdc++.h>

void solve(){
    std::string s;
    std::getline(std::cin, s);
    long long a = s[0]-48;
    long long b = s[2]-48;

    std::cout<<a+b<<'\n';
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