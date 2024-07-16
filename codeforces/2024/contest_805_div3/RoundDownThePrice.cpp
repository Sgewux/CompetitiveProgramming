#include <bits/stdc++.h>

void solve(){
    long long m;
    std::cin>>m;
    long long ans;
    long long i = 10;

    while (std::pow(10,i) > m){
        i--;
    }

    std::cout<<(long long)(m-std::pow(10,i))<<'\n';
    
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