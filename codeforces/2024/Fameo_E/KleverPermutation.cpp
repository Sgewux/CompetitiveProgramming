#include <bits/stdc++.h>

void solve(){
    long long n;
    long long k;
    std::cin>>n;
    std::cin>>k;
    std::vector<long long>p(n,-1);

    long long i = 0;
    long long pi = 1;
    bool topSwap = false;
    while(p[i] == -1){
        long long l = i;
        long long r = i;
        for(long long j = i; j<n; j+=k){
            p[j] = pi;
            pi++;
            r = j;
        }

        if(topSwap){
            while(l < r){
                std::swap(p[l], p[r]);
                l+=k;
                r-=k;
            }
        }

        i++;
        topSwap = !topSwap;

    }
    
    for(long long i = 0; i<n; i++){
        std::cout<<p[i]<<' ';
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
