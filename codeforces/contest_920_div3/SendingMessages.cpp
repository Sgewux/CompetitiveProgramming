#include <bits/stdc++.h>

void solve(){
    long long n;
    long long f;
    long long a;
    long long b;
    long long curr;
    long long spent = 0;
    std::cin>>n;
    std::vector<long long> s(n+1, 0);

    std::cin>>f;
    std::cin>>a;
    std::cin>>b;

    for(long long i = 0; i<n; i++){
       std::cin>>curr;
       s[i+1] = curr;

       spent = a*(curr - s[i]) < b ? spent + a*(curr - s[i]) : spent + b;
    }

    if(spent < f){
        std::cout<<"YES";
    } else {
        std::cout<<"NO";
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
        std::cout<<'\n';
    }

    return 0;
}