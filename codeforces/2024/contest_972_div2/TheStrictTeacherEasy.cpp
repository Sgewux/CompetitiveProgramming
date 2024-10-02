#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n; ll m; ll q;
    cin>>n>>m>>q;
    ll t1; ll t2; ll d;
    cin>>t1>>t2>>d;
    if(t1 > t2) swap(t1,t2);

    if(d > t1 &&   d < t2){
        ll ans  = (abs(abs(d-t1) - abs(d-t2)))/2;
        ans += min(abs(d-t1), abs(d-t2));
        cout<< ans;
    } else {
        if(d < t1){
            cout<<abs((d-1) + abs(d-t1));
        } else {
            cout<<abs(d-n) + abs(d-t2);
        }
    }

    cout<<'\n';
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