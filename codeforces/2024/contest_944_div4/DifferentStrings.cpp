#include <bits/stdc++.h>

void solve(){
    std::string s;
    std::string r;
    std::getline(std::cin, s);

    for(long long i = 0; i<s.length()-1; i++){
        if(s[i] != s[i+1]){
            std::swap(s[i], s[i+1]);
            std::cout<<"YES"<<'\n';
            std::cout<<s<<'\n';
            return;
        }
    }

    std::cout<< "NO" <<'\n';
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