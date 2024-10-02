#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll f(ll x, ll u){
    return x*u - (x*(x-1)/2);
}

void solve(){
    ll n;
    ll q;
    ll ql;
    ll u;
    cin>>n;
    vector<ll> a(n+1,0);
    
    for(ll i = 1; i<=n; i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }
    
    cin>>q;
    
    while(q--){
        cin>>ql>>u;
        if(a[n]-a[ql-1] <= u){
            cout<<n<<' ';
        } else if(a[ql] - a[ql-1] > u){
            cout<<ql<<' ';
        } else {
            ll l = ql;
            ll r = n;
            ll m;
            ll a1; ll a2;
            
            while(l < r){
                m = (l+r)/2;
                if(a[m] - a[ql-1] < u){
                    l = m+1;
                } else if(a[m] - a[ql-1] > u){
                    r = m-1;
                } else {
                    a1 = m;
                    a2 = m;
                    break;
                }
            }
            
            m = (l+r)/2;
    
            if(a[m] - a[ql-1] > u){
                a1 = m-1;
                a2 = m;
            } else {
                a1 = m;
                a2 = m+1 <= n ? m+1 : m;
            }
            
            cout<<(f(a[a2] - a[ql-1], u) > f(a[a1] - a[ql-1], u) ? a2 : a1)<<' ';
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