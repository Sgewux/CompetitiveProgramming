#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll binexpo(ll a, ll b){
    if(b == 0) return 1;
    
    ll res = binexpo(a, b/2);
    
    if(b & 1){
        return res * res * a;
    } else {
        return res * res;
    }
}

void solve(){
    ll m;
    cin>>m;

    for(long long i = 2; i<=54; i++){
        ll sum = 0;
        ll j = 1;
        while(sum <= m){
            sum += binexpo(j, i);
            if(sum > m || sum < 0){
                break;
            }else if(sum == m){
                cout<<i+1<<' '<<j;
                return;
            }

            j++;
        }
    }

    cout<<"impossible";
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