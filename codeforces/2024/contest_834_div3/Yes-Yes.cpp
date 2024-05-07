#include <bits/stdc++.h>

void solve(){
    std::string s;
    std::getline(std::cin, s);
    std::set<std::string> allowed({"Y", "e", "s", "Ye", "es", "sY", "Yes", "esY", "sYe"});

    if(s.length() < 3){
        std::cout<< (allowed.count(s) ? "YES" : "NO")<<'\n';
    } else {
        long long i = 0;
        bool possible = true;
        while(i+2 < s.length()){
            possible = possible && allowed.count(s.substr(i,3));
            i++;
        }

        std::cout<<(possible ? "YES" : "NO")<<'\n';
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