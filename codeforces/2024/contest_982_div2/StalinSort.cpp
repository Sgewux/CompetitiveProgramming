#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    vector<vector<ll>>p(n, vector<ll>(n,0));
    for(long long i = 0; i<n; i++){
        cin>>a[i];
    }
    ll ans = 1e9;

    for(long long i = 0; i<n; i++){
        bool g = false;
        for(long long j = i+1; j<n; j++){
            if(a[i] >= a[j]){
                p[i][j] = p[i][j-1] + 1;
            } else {
                p[i][j] = p[i][j-1];
            }
        }
    }

    for(long long i = 0; i<n; i++){
        ll currAns = i;
        for(long long j = 0; j<i; j++){
            if(a[j] >= a[i]){
                ll c = i - p[j][i-1] - 1;
                currAns = min(currAns, c);
            }
        }

        for(long long j = i+1; j<n; j++){
            if(a[j] > a[i] ) currAns++;
        }

        ans = min(ans, currAns);
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