#include <bits/stdc++.h>
#define ll long long 

void solve(){
    ll n;
    std::cin>>n;
    std::vector<ll>ans(n);
    std::vector<ll>b(n-1);

    for(long long i = 0; i<n-1; i++){
        std::cin>>b[i];
    }

    if(n-1 == 1){
        std::cout<<b[0] << ' '<<b[0]<<'\n';
        return;
    } else {
        ans[0] = b[0];
        ans[n-1] = b[n-2];

        for(long long i = 1; i<n-1; i++){
            ans[i] = (b[i] | b[i-1]);
        }



        for(long long i = 0; i<n-1; i++){
            if(b[i] != (ans[i] & ans[i+1])){
                std::cout<<-1<<'\n';
                return;
            }
        }

        for(long long i = 0; i<n; i++){
            std::cout<<ans[i]<<' ';
        }
        std::cout<<'\n';
    }
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