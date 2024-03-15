#include <bits/stdc++.h>

void solve(long long l, long long r, long long currD, std::vector<long long>& a, std::vector<long long>& d){
    if(l>r){
        return;
    } else {
        long long currMax = -1e9;
        long long maxIdx = -1;
        
        for(long long i = l; i<=r; i++){
            if(a[i] > currMax){
                currMax = a[i];
                maxIdx = i;
            }
        }

        d[maxIdx] = currD;
        solve(l, maxIdx-1, currD+1, a, d);
        solve(maxIdx+1, r, currD+1, a, d);
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long curr;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::vector<long long>a;
        std::vector<long long>d(n,0);

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            a.push_back(curr);
        }

        solve(0, n-1, 0, a, d);

        for(long long i = 0; i<n; i++){
            std::cout<<d[i]<<' ';
        }
        std::cout<<'\n';

    }

    return 0;
}