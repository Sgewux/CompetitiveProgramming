#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    std::cin>>n;
    std::unordered_set<long long> remainders;
    std::vector<long long>v;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        v.push_back(curr);
    }

    for(long long i = 1; i<=59; i++){
        long long power = std::pow(2,i);

        for(long long i = 0; i<n; i++){
            remainders.insert(v[i] & (power - 1));
        }

        if(remainders.size() == 2){
            std::cout<<power<<'\n';
            return;
        }

        remainders.clear();
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