#include <bits/stdc++.h>

void solve(){
    long long n;
    long long m;

    std::cin>>n;
    std::cin>>m;
    std::vector<long long> v(n+2,0);
    std::vector<long long> on(n+2, 0);
    v[n+1] = m;

    for(long long i = 1; i<n+1; i++){
        std::cin>>v[i];
        on[i] = on[i-1] + (i%2)*(v[i] - v[i-1]);
    }

    on[n+1] = on[n] + ((n+1)%2)*(v[n+1] - v[n]);

    long long ans = on[n+1];

    for(long long i = 0; i<n+1; i++){
        if(i%2 != 0){
            if(i-1 >= 0 && v[i]-1 != v[i-1]){
                long long xd = on[i] - 1 + ((m-v[i]) - (on[n+1]-on[i]));
                ans = std::max(ans, xd);
            }

            if(i+1<n+2 && v[i]+1 != v[i+1]){
                long long xd = on[i] + 1 + (((m-1)-v[i]-1) - (on[n+1]-on[i]));
                ans = std::max(ans, xd);
            }
        }
    }

    std::cout<<ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t = 1;

    while(t--){
        solve();
    }

    return 0;
}