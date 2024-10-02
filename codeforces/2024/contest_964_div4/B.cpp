#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll a1;
    ll a2; 
    ll b1;
    ll b2;

    cin>> a1>>a2>>b1>>b2;

    ll ans = 0;

    if(a1 >= b1 ) {
        if(a1>b1 && a2>=b2){
            ans++;
        } else if(a2>b2){
            ans++;
        }
    }

    if(a1>=b2){
        if(a1>b2 && a2>=b1){
            ans++;
        } else if(a2 > b1){
            ans++;
        }
    }

    if(a2>=b2){
        if(a2>b2 && a1>=b1){
            ans++;
        } else if(a1 > b1){
            ans++;
        }
    }

    if(a2>=b1){
        if(a2>b1 && a1>=b2){
            ans++;
        } else if(a1 > b2){
            ans++;
        }
    }

    cout<<ans<<'\n';

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