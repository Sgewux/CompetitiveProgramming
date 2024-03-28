#include <bits/stdc++.h>

long long solve(long long n, long long x, long long k, std::vector<long long>& v){
    std::unordered_map<long long, long long>s;
    s[0] = 0;
    long long ans = -3e9 -1;
    long long currSum = 0;
    for(long long i = 0; i<n; i++){
        currSum+=v[i];
        s[i+1] = currSum;
    }


    for(long long i = 0; i<=k; i++){
        if(n-i > x){
            ans = std::max(ans, s[n-i-x] - (s[n-i] - s[n-i-x]));
        } else {
            ans = std::max(ans, (-1) * s[n-k]);
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
    long long x;
    long long k;
    long long curr;
    std::cin>>t;

    while(t--){
        std::vector<long long>v;
        std::cin>>n;
        std::cin>>k;
        std::cin>>x;
        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            v.push_back(curr);
        }
        std::sort(v.begin(), v.end());
        std::cout<<solve(n,x,k,v);
        std::cout<<'\n';
    }

    return 0;
}