#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(long long i = 0; i<n; i++){
        cin>>a[i];
    }

    set<ll> available;
    available.insert(a[0]-1);
    available.insert(a[0] + 1);

    for(long long i = 1; i<n; i++){
        if(available.count(a[i])){
            available.erase(a[i]);
            available.insert(a[i] + 1);
            available.insert(a[i] - 1);
        } else {
            cout<<"NO"<<'\n';
            return;
        }
    }

    cout<<"YES"<<'\n';
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