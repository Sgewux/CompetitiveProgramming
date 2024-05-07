#include <bits/stdc++.h>

void solve(){
    long long m;
    long long s;
    long long curr;
    long long max = -1;
    std::unordered_set<long long>b;
    std::cin>>m;
    std::cin>>s;

    for(long long i = 0; i<m; i++){
        std::cin>>curr;
        max = std::max(max, curr);
        b.insert(curr);
    }

    for(long long i = 1; i<=max; i++){
        if(!b.count(i)){
            s -= i;
        }
    }

    while(s >= max){
        s-= max+1;
        max++;
    }

    std::cout<<(s == 0 ? "YES" : "NO")<<'\n';

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