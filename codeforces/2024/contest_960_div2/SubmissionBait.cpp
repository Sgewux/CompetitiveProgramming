#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    std::cin>>n;
    std::map<long long, long long> freq;
    long long max = -1;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        max = std::max(max, curr);
        freq[curr]++;
    }

    for(auto& f : freq){
        if(f.second % 2 != 0){
            std::cout<<"YES"<<'\n';
            return;
        }
    }

    std::cout<<"NO"<<'\n';
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