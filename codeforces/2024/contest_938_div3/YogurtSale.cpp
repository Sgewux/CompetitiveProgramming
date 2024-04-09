#include <bits/stdc++.h>

void solve(){
    long long n;
    long long a;
    long long b;

    std::cin>>n;
    std::cin>>a;
    std::cin>>b;

    if(b < 2*a){
        std::cout<< b*(std::floor(n/2)) + a*(n%2)<<'\n';
    } else {
        std::cout<< a*(n)<<'\n';
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