#include <bits/stdc++.h>
#define ll long long

void solve(){
    ll n;
    ll q;
    ll l;
    ll r;
    ll curr;
    std::cin>>n>>q;
    std::vector<ll>pu(n+1,0);
    std::vector<ll>po(n+1,0);

    for(long long i = 1; i<=n; i++){
        std::cin>>curr;
        pu[i] = pu[i-1] + curr-1;
        po[i] = po[i-1];
        if(curr == 1) po[i]++;
    }

    for(long long i = 0; i<q; i++){
        std::cin>>l>>r;
        if(l == r){
            std::cout<<"NO";
        } else {
            std::cout<<(pu[r] - pu[l-1] >= po[r] - po[l-1] ? "YES" : "NO");
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