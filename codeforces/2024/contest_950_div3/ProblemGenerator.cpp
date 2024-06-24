#include <bits/stdc++.h>

void solve(){
    long long n;
    long long m;
    std::string a;
    std::map<char, long long> cnt;
    std::vector<char> chars = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    long long ans = 0;

    std::cin>>n;
    std::cin>>m;
    std::cin.ignore();
    std::getline(std::cin, a);

    for(long long i = 0; i<n; i++){
        cnt[a[i]]++;
    }

    for(auto& c : chars){
        ans += cnt[c] < m ? m-cnt[c] : 0;
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