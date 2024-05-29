#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin>>n;
    std::vector<long long> s(n);
    std::vector<long long> f(n);
    std::vector<long long> d;

    for(long long i = 0; i<n; i++){
        std::cin>>s[i];
    }

    for(long long i = 0; i<n; i++){
        std::cin>>f[i];
    }

    d.push_back(f[0] - s[0]);

    for(long long i = 1; i<n; i++){
        if(s[i] > f[i-1]){
            d.push_back(f[i] - s[i]);
        } else {
            d.push_back(f[i]-f[i-1]);
        }
    }

    for(long long i = 0; i<n; i++){
        std::cout<<d[i]<<' ';
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