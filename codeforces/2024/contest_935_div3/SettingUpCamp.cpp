#include <bits/stdc++.h>

void solve(){
    long long a;
    long long b;
    long long c;
    long long ans = 0;

    std::cin>>a;
    std::cin>>b;
    std::cin>>c;

    ans += a;
    ans += std::floor(b/3);

    if(b%3 != 0){
        if( 3-(b%3) > c){
            std::cout<<-1<<'\n';
            return;
        } else {
            ans++;
            c-=(3-(b%3));
        }
    }

    ans+= c%3 == 0 ? c/3 : std::floor(c/3) + 1;

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