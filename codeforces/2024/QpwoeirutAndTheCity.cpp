#include <bits/stdc++.h>

void solve(){
    long long n;
    long long acc = 0;
    long long ans;
    long long curr;
    std::vector<long long>v;
    std::cin>>n;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        v.push_back(curr);
    }

    for(long long i = ((n%2 == 0) ? 2 : 1); i<n-1; i+=2){
       acc += (v[i-1] < v[i]) && (v[i] > v[i+1]) ? 0 : std::max(v[i-1], v[i+1]) - v[i] + 1;
    }

    ans = acc;

    if(n%2 != 0){
        std::cout<<ans;
    } else {
        for(long long i = 1; i<n-2; i+=2){
            long long x = (v[i-1] < v[i]) && (v[i] > v[i+1]) ? 0 : std::max(v[i-1], v[i+1]) - v[i] + 1;
            long long y = (v[i] < v[i+1]) && (v[i+1] > v[i+2]) ? 0 : std::max(v[i], v[i+2]) - v[i+1] + 1;

            acc = acc-y+x;
            ans = std::min(ans, acc);
        }
        std::cout<<ans;
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