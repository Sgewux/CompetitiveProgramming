#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n; ll k;
    cin>>n>>k;
    ll ans = 1;
    for(long long i = 2; i<=k; i++){
        ll a = 1;
        ll b = 1;
        for(long long j = n; j>n-i; j--) a*=j;
        for(long long j = 1; j<=i; j++) b*=j;

        if(i == 2){
            ans += (a/b);
        } else if(i == 3){
            ans += (a/b)*2;
        } else {
            ans += (a/b)*9;
        }
    }

    cout<<ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t=1;

    while(t--){
        solve();
    }

    return 0;
}