#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll m;
    ll xi;
    ll di;
    ll sum = 0;
    cin>>n>>m;

    for(long long j = 0; j<m; j++){
        cin>>xi>>di;
        ll q;
        if(di > 0){
            q = (n*(n-1)/2);
        } else {
            if(n%2 != 0){
                q = (n/2)*(n/2 + 1);
            } else {
                q = ((n/2)*(n/2 + 1)/2) + ((n/2)*(n/2 - 1)/2);
            }
        }
        
        sum += n*xi + di*q;
    }

    cout<< fixed << setprecision(15) << ((double)sum/n);
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