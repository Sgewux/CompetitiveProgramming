#include <bits/stdc++.h>

void solve(long long n, long long m, std::deque<long long>&a, std::deque<long long>&b){
    long long ans = 0;
    for(long long i = 0; i<n-m; i++){
        ans += std::min(a[i], b[i]);
    }

    if(m == 1){
        ans += a[n-1];
    } else {
        long long sum = 0;
        long long min =2e9;
        for(long long i = n-m; i<n-1; i++){
            sum += b[i];
            min = std::min(min, sum + a[i+1]);
        }

        if(min < a[n-m]){
            ans += min;
        } else {
            ans+= a[n-m];
        }
    }

    std::cout<<ans<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);

    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long m;
    long long curr;
    std::cin>>t;

    while(t--){
        std::deque<long long>a;
        std::deque<long long>b;
        std::cin>>n;
        std::cin>>m;

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            a.push_front(curr);
        }

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            b.push_front(curr);
        }
       
       solve(n, m, a, b);
    }

    return 0;
}