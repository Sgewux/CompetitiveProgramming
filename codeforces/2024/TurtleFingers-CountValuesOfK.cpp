#include <bits/stdc++.h>

void solve(){
    long long ans = 0;
    long long a;
    long long b;
    long long l;

    std::set<long long>k;

    std::cin>>a;
    std::cin>>b;
    std::cin>>l;

    for(long long i = 1; i <= l; i*=a){
        for(long long j = 1; j<=l; j*=b){
            if(l%(i*j) == 0){
                if(!k.count(l/(i*j)) ){
                    ans++;
                    k.insert(l/(i*j));
                }
           }
        }
    }

    std::cout<<ans<<'\n'; //I could have written "k.size()" instead of counting unnecessary stuff :(
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