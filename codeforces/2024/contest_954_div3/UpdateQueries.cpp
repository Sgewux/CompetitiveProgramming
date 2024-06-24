#include <bits/stdc++.h>

void solve(){
    long long n;
    long long m;
    std::cin>>n;
    std::cin>>m;

    std::string s;
    std::cin.ignore();
    std::getline(std::cin, s);

    std::vector<long long> idx;
    std::set<long long> seen;

    for(long long i = 0; i<m; i++){
        long long curr;
        std::cin>>curr;
        if(!seen.count(curr)){
            idx.push_back(curr);
        }
        seen.insert(curr);
    }
    std::cin.ignore();
    std::string c;
    std::getline(std::cin, c);

    std::sort(idx.begin(), idx.end());
    std::sort(c.begin(), c.end(), std::greater<char>());

    for(auto & i : idx){
        s[i-1] = c.back();
        c.pop_back();
    }

    std::cout<<s<<'\n';
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