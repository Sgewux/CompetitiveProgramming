#include <bits/stdc++.h>

void solve(){
    std::string s;
    std::getline(std::cin, s);

    if( (s[0] == 'Y' || s[0] == 'y') && (s[1] == 'E' || s[1] == 'e') && (s[2] == 'S' || s[2] == 's')){
        std::cout<<"YES";
    } else {
        std::cout<<"NO";
    }

    std::cout<<'\n';
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