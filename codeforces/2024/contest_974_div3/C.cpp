#include <bits/stdc++.h>
#define ll long long
#define ld long double
using namespace std;

bool unhappy(vector<ll>& a, ll n, ll x, ld avg){
    avg += x;
    avg /= n;
    return ((ld)a[n/2] < (avg/2));
}

ll f(vector<ll>& a, ll n, ld avg){
    ll l = 0; ll r = 1e18;
    ll x;
    bool found = false;
    ll ans = 1e18;

    while(l <= r){
        x = (l+r)/2;
        if(unhappy(a,n,x,avg)){
            found = true;
            ans = min(ans, x);
            r = x-1;
        } else {
            l = x+1;
        }
    }

    if(found){
        return ans;
    } else {
        return -1;
    }
}

void solve(){
    ll n;
    cin>>n;
    vector<ll> a(n);
    ld avg = 0;

    for(long long i = 0; i<n; i++) cin>>a[i];
    sort(a.begin(), a.end());
    for(long long i = 0; i<n; i++) avg+=a[i];
    if(n == 1 || n == 2){
        cout<<-1<<'\n';
        return;
    }
    assert(f(a,n,avg) != -1);
    cout<<f(a,n,avg)<<'\n';


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