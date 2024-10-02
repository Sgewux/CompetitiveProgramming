#include <bits/stdc++.h>

void solve(){
    long long n;
    long long k;
    std::cin>>n>>k;
    std::cin.ignore();
    std::vector<std::string>m(n);
    std::vector<std::vector<int>> ans;
    std::string row;

    for(long long i = 0; i<n; i++){
        std::getline(std::cin, row);
        m[i] = row;
    }

    for(long long i = 0; i<n; i+=k){
        long long j = 0;
        std::vector<int> ansRow;
        while(j < n){
            std::string s = m[i].substr(j,k);
            if(s.back() == '1'){
                ansRow.push_back(1);
            } else {
                ansRow.push_back(0);
            }

            j+=k;
        }
        ans.push_back(ansRow);
    }

    for(auto& r : ans){
        for(auto& e : r){
            std::cout<<e;
        }
        std::cout<<'\n';
    }
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