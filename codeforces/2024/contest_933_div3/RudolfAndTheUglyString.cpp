#include <bits/stdc++.h>

void solve(){
    long long n;
    std::string s;
    std::cin>>n;

    std::cin.ignore();
    std::getline(std::cin, s);
    std::map<std::string, int> m;

    long long i = 0;
    while(i < n-2){
        if(s.substr(i, 3) == "map" || s.substr(i, 3) == "pie"){
            m[s.substr(i, 3)]++;
        }
        i++;
    }

    i = 0;

    while(i < n-4){
        if(s.substr(i, 5) == "mapie" ){
            m[s.substr(i, 5)]++;
        }
        i++;
    }

    std::cout<<(m["map"] + m["pie"] - m["mapie"])<<'\n';
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