#include <bits/stdc++.h>

long long solve(long long n, long long min, std::vector<long long>&v){
    long long ans = min > 0 ? min-1 : 0;
    
    if(n>1){
        if(min != 0){
            ans += v[0]-min;
        } else {
            ans += v[0]-1;
        }
    }
   

    for(long long i = 1; i<n; i++){
        if(v[i] > v[i-1]){
            ans += v[i]-v[i-1];
        }
    }

    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long curr;
    long long min;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::vector<long long>v;
        min = 1e9 + 1;
        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            min = std::min(min, curr);
            v.push_back(curr);
        }

        std::cout<<solve(n,min,v)<<'\n';
    }

    return 0;
}