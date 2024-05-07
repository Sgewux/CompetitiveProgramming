#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    std::cin>>n;
    std::vector<long long>x;
    std::vector<long long>a(n,0);
    a[n-1] = 1e9;

    for(long long i = 0; i<n-1; i++){
        std::cin>>curr;
        x.push_back(curr);
    }

    for(long long i = n-2; i>=0; i--){
        a[i] = a[i+1] - x[i];
    }

    for(long long i = 0; i<n; i++){
        std::cout<<a[i] <<' ';
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