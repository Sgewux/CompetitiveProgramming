#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin>>n;
    std::cin.ignore();
    std::string curr;

    std::set<std::string> avaiable;
    std::vector<std::string> s;
    std::vector<long long> ans(n, 0);

    for(long long i = 0; i<n; i++){
        std::getline(std::cin, curr);
        avaiable.insert(curr);
        s.push_back(curr);
    }

    for(long long i = 0; i<n; i++){
        curr = s[i];
        long long len = 1;
        while(len < curr.length() && ans[i] == 0){
            std::string prefix = curr.substr(0, len);
            std::string suffix = curr.substr(len, curr.length() - len);
            if(avaiable.count(prefix) && avaiable.count(suffix)){
                ans[i] = 1;
            }
            len++;
        }
    }

    for(long long i = 0; i<n; i++){
        std::cout<<ans[i];
    }

    std::cout<<'\n';
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