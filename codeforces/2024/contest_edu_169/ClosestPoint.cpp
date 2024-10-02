#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<ll>p(n);;

    for(long long i = 0; i<n; i++){
        cin>>p[i];
    }

    if(n == 2){
        if(abs(p[0] - p[1]) > 1){
            cout<<"YES"<<'\n';
        } else {
            cout<<"NO"<<'\n';
        }
    }  else {
        cout<<"NO"<<'\n';
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