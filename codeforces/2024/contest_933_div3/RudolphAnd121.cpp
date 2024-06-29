#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin>>n;

    std::vector<long long>a(n);

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
    }

    for(long long i = 1; i<n-1; i++){
        long long actions = std::min(a[i-1], a[i+1]);
        actions = std::min(actions, (long long)std::floor(a[i]/2));
        a[i-1]-=actions;
        a[i] -= 2*actions;
        a[i+1] -=actions;
    }

    for(long long i = 0; i<n; i++){
        if(a[i] != 0){
            std::cout<<"NO"<< '\n';
            return;
        }
    }

    std::cout<< "YES" << '\n';
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