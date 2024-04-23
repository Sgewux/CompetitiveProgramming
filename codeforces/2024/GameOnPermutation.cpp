#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    long long min = 1e9;
    long long minA = 1e9;
    long long ans = 0;
    std::cin>>n;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        if(curr>min && curr<minA){
            ans++;
            minA = curr;
        }

        min = std::min(min, curr);
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