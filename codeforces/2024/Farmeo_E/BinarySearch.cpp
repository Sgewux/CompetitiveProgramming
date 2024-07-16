#include <bits/stdc++.h>

void solve(){
    long long n;
    long long x;
    std::cin>>n;
    std::cin>>x;
    std::vector<long long>a(n);
    long long p;

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
        if(a[i] == x){
            p = i;
        }
    }

    long long l = 0;
    long long r = n;

    while(r-l > 1){
        long long m = (l+r)/2;
        if(a[m] <= x){
            l=m;
        } else {
            r=m;
        }
    }

    if(a[l] == x){
        std::cout<<0<<'\n';
    } else {
        std::cout<<1<<'\n';
        std::cout<<p+1<<" "<<l+1<<'\n';
    }
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