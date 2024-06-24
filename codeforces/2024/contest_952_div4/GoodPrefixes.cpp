#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin>>n;
    std::vector<long long>a(n);

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
    }

    std::set<long long> s;
    s.insert(0);
    long long sum = 0;
    long long ans = 0;

    for(long long i = 0; i<n; i++){
        sum += a[i];
        s.insert(2*a[i]);

        if(s.count(sum)){
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