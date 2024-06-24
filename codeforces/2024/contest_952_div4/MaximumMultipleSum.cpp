#include <bits/stdc++.h>

void solve(){
    long long n;
    long long ans = 0;
    long long x = 0;
    std::cin>>n;

    for(long long i = 2; i<=n; i++){
        long long sum =0;
        long long k=1;
        while (i*k <= n){
            sum += i*k;
            k++;
        }

        if(sum > ans){
            ans = sum;
            x =i;
        }
        
    }

    std::cout<<x<<'\n';
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