#include <bits/stdc++.h>

struct sort_chars {
    bool operator()(std::pair<char, int>& l, std::pair<char, int>& r){
        return l.first < r.first;
    }
};

struct sort_index {
    bool operator()(std::pair<char, int>& l, std::pair<char, int>& r){
        return l.second < r.second;
    }
};
void solve(){
    std::cin.ignore();
    std::string s;
    long long p;
    long long score =0;
    std::getline(std::cin, s);
    std::cin>>p;

    std::vector<std::pair<char,int>> v;
    for(long long i = 0; i < s.length(); i++){
        v.push_back({s[i], i});
        score += s[i]-96;
    }

    std::sort(v.begin(), v.end(), sort_chars());

    while(score > p && !v.empty()){
        score -= v.back().first -96;
        v.pop_back();
    }

    std::sort(v.begin(), v.end(), sort_index());

    for(auto& e : v){
        std::cout << e.first;
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