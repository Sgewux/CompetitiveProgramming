#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll k;
    cin>>n>>k;
    vector<ll> a(n);

    for(long long i = 0; i<n; i++){
        cin>>a[i];
    }

    sort(a.begin(), a.end(), greater<ll>());
    ll A = 0;
    ll B = 0;
    for(long long i = 0; i<n; i++){
        if(i%2 != 0){
            if(a[i-1] - a[i] <= k){
                k -= a[i-1] - a[i];
                a[i] = a[i-1];
            } else {
                a[i] += k;
                k = 0;
            }
        } 

        if(i%2 == 0){
            A+=a[i];
        } else {
            B+=a[i];
        }
    }

    cout<<A-B<<'\n';
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