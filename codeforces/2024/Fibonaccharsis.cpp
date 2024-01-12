#include <bits/stdc++.h>

long long solve(long long n, long long k){
    long long ans = 0;
    long long start = n%2 == 0 ? n/2 : std::floor(n/2) + 1;

    for(long long i = start; i <= n; i++){
        long long currK = 2;
        long long currLastA = n;
        long long currLastB = i;
        long long diff = currLastA - currLastB;

        while(diff>=0 && currK<=k){
            diff = currLastA - currLastB;
            if(diff>currLastB){
                break;
            }
            currLastA = currLastB;
            currLastB = diff;

            currK++;

            if(currK == k){
                ans++;
            }

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
    long long k;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::cin>>k;

        std::cout<<solve(n,k)<<'\n';
    }

    return 0;
}