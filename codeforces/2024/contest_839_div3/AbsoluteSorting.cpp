#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    long long a;
    long long b;
    long long ans = 0;
    std::vector<long long>v;
    std::cin>>n;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        v.push_back(curr);
    }

    for(long long i = 0; i<n-1; i++){
        a = v[i];
        b = v[i+1];

        if(a > b){
            if(a-b-1 <= 1){
                ans = std::max(ans, b+1);
            } else {
                long long extra = (a-b-2)%2 == 0 ? (a-b-2)/2 : std::floor((a-b-2)/2) + 1 ;
                ans = std::max(ans, (b+1)+extra);
            }
        }
    }

    for(long long i = 0; i<n-1; i++){
        if( std::abs(v[i] - ans) > std::abs(v[i+1] - ans)){
            std::cout<<-1<<'\n';
            return;
        }
    }

    std::cout<<ans<<'\n';
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