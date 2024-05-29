#include <bits/stdc++.h>

void solve(){
    long long n;
    long long currDiff;
    std::cin>>n;
    std::vector<long long>a(n);
    std::vector<long long>b(n);
    long long maxDiff = 0;

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
    }

    for(long long i = 0; i<n; i++){
        std::cin>>b[i];
        maxDiff = std::max(a[i] - b[i], maxDiff);
    }



    for(long long i = 0; i<n; i++){
        a[i]-=maxDiff;
        if(a[i] < 0){
            a[i] = 0;
        }
        if(a[i] != b[i]){
            std::cout<<"NO"<<'\n';
            return;
        }
    }

    std::cout<<"YES"<<'\n';
    
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