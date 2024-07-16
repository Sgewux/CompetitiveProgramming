#include <bits/stdc++.h>

void solve(){
    std::string s;
    std::set<char> m;
    long long memo = 0;
    long long ans = 0;
    std::getline(std::cin, s);

    for(auto& c : s){

        if(!m.count(c)){
            m.insert(c);
            memo++;

            if(memo == 4){
                ans++;
                memo = 1;
                m.clear();
                m.insert(c);
            }
        }
    }

    if(memo != 0){
        ans++;
    }

    std::cout<<ans<<'\n';
    
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