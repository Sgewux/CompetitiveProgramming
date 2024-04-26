#include <bits/stdc++.h>

long long solve(long long n, long long i, std::vector<long long>& a, std::vector<bool>& marked){
    if(i == n){
        long long ans = 0;
        for(long long i = 0; i<n; i++){
            if(marked[i]){
                ans += a[i];
            } else {
                ans -= a[i];
            }
        }

        return std::abs(ans);
    } else {
        marked[i] = true;
        long long x = solve(n, i+1, a, marked);
        marked[i] = false;
        long long y = solve(n, i+1, a, marked);

        return std::min(x,y);
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t = 1;
    long long n;
    long long curr;

    while(t--){
        std::cin>>n;
        std::vector<long long>a;
        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            a.push_back(curr);
        }

        std::vector<bool> marked(n, 0);

        std::cout<<solve(n, 0, a, marked)<<'\n';
    }

    return 0;
}