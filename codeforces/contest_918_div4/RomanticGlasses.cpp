#include <bits/stdc++.h>

void solve(){
    long long n;
    long long a = 0;
    long long b = 0;
    long long curr;
    std::string ans = "NO";
    std::set<long long> diffacc;
    std::cin>>n;

    for(long long i = 0; i<n; i++){
       std::cin>>curr;
       if((i+1)%2 != 0){
            a+=curr;
        } else {
            b+=curr;
        }

        long long diff = a-b;

        if(diffacc.count(diff) || diff == 0){
            ans = "YES";
        } else {
            diffacc.insert(diff);
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