#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    long long max = -1e10; 
    std::vector<long long>z;
    std::vector<long long>strong;
    std::cin>>n;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        z.push_back(curr);
    }

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        z[i]-=curr;
        max = std::max(max, z[i]);
    }

    for(long long i = 0; i<n; i++){
        if(z[i] == max){
            strong.push_back(i+1);
        }
    }

    std::cout<<strong.size()<<'\n';
    for(auto& e : strong){
        std::cout<<e <<' ';
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