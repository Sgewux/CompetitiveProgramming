#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll a; ll b; ll c;
    cin>>a>>b>>c;

    if(a<b && a<c) {
        cout<<"First"<<'\n';
    } else if(b < a && b< c){
        cout<<"Second"<<'\n';
    } else {
        cout<<"Third"<<'\n';
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    cin>>t;

    while(t--){
        solve();
    }

    return 0;
}