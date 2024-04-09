#include <bits/stdc++.h>

void solve(){
    long long a;
    long long b;
    long long m;

    std::cin>>a;
    std::cin>>b;
    std::cin>>m;

    long long ans = (m/a) + (m/b) + 2;
    std::cout<<ans<<'\n';;
   

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