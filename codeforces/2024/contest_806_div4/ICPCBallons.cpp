#include <bits/stdc++.h>

void solve(){
    long long n;
    std::string s;
    std::cin>>n;
    std::cin.ignore();
    std::getline(std::cin, s);
    std::set<char> seen;

    long long ans = 0;

    for(long long i = 0; i<n; i++){
        if(!seen.count(s[i])){
            ans += 2;
            seen.insert(s[i]);
        } else {
            ans++;
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