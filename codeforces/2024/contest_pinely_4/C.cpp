#include <bits/stdc++.h>
#define ll long long

void solve(){
    ll n;
    ll curr;
    ll e = 0;
    ll o = 0;
    std::cin>>n;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        if(curr%2 == 0){
            e++;
        } else {
            o++;
        }
    }

    if(e && o){
        std::cout<<-1<<'\n';
    } else {
        if(e){
            std::cout<<31<<'\n';
        } else {
            std::cout<<30<<'\n';
        }

        for(long long i = 29; i>=0; i--){
            std::cout<<(ll)std::pow(2,i)<<' ';
        }

        if(e) std::cout<<1;
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