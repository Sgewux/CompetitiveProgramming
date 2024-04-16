#include <bits/stdc++.h>

void solve(){
    long long k;
    long long n;
    std::cin>>k;
    std::cin>>n;

    std::vector<long long>v = {1,2};
    long long lastDiff = 1;

    for(long long i = 0; i<k-2; i++){
        long long t = (v.back() + lastDiff + 1);
        if(t <= n && n-t >= k-(v.size()+1) ){
            lastDiff = t - v.back();
            v.push_back(t);
        } else {
            lastDiff = 1;
            v.push_back(v.back() + 1);
        }
    }

    for(long long i = 0; i<k; i++){
        std::cout<<v[i]<<' ';
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