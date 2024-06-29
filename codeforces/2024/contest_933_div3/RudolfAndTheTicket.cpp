#include <bits/stdc++.h>

void solve(){
    long long n;
    long long m;
    long long k;
    std::cin>>n;
    std::cin>>m;
    std::cin>>k;

    std::vector<long long> s(n);
    std::vector<long long> c(m);

    for(long long i = 0; i<n; i++){
        std::cin>>s[i];
    }

    for(long long i = 0; i<m; i++){
        std::cin>>c[i];
    }
    long long ans = 0;
    for(long long i = 0; i<n; i++){
        for(long long j = 0; j<m; j++){
            if(s[i] + c[j] <= k) {
                ans++;
            }
        }
    }

    std::cout<<ans<<'\n';
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