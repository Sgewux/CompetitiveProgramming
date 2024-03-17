#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    long long minElement = 1e9 + 1;
    long long minIdx = -1;
    std::vector<long long>a;
    
    std::cin>>n;

    for(long long i = 0; i<n; i++){
       std::cin>>curr;
       a.push_back(curr);
       if(curr <minElement){
            minElement = curr;
            minIdx = i;
        }
    }

    for(long long i = minIdx; i<n-1; i++){
        if(!(a[i] <= a[i+1])){
            std::cout<<-1<<'\n';
            return;
        }
    }

    std::cout<<minIdx<<'\n';
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