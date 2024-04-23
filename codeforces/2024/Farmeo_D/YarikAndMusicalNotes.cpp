#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    long long ans = 0;
    std::map<long long, long long> m;

    std::cin>>n;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        if(curr == 2 || curr == 1){
            ans+=m[2]+m[1];
        } else {
            ans+=m[curr];
        }

        m[curr]++;

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