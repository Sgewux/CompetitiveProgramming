#include <bits/stdc++.h>
#define ll long long
 
using namespace std;
 
const ll N = 2e5;
ll t[4*N];
 
void build(ll v, ll l, ll r, vector<ll>& a){
    if(l == r){
        t[v] = a[l];
    } else {
        ll m = (l+r)/2;
        build(2*v, l, m, a);
        build(2*v + 1, m+1, r, a);
 
        t[v] = max(t[2*v], t[2*v + 1]);
    }
}
 
void update(ll v, ll l, ll r, ll pos, ll val){
    if(l == r){
        t[v] = val;
    } else {
        ll m = (l+r)/2;
 
        if(pos <= m){
            update(2*v, l, m, pos, val);
        } else {
            update(2*v + 1, m+1, r, pos, val);
        }
 
        t[v] = max(t[2*v], t[2*v + 1]);
    }
}
 
ll query(ll v, ll l, ll r, ll ql, ll qr){
    if(qr < ql){
        return -1;
    }else if(l == ql && r == qr){
        return t[v];
    } else {
        ll m = (l+r)/2;
        ll a = query(2*v, l, m, ql, min(m, qr));
        ll b = query(2*v + 1, m+1, r, max(m+1, ql), qr);
 
        return max(a,b);
    }
}
 
void solve(){
    ll n; cin>>n;
    vector<ll>v(n+1, 0);
    set<ll>vp;
    map<ll,ll> cord;
    build(1,0,n, v);
    for(long long i = 0; i<n; i++) {
        cin>>v[i];
        vp.insert(v[i]);
    }
    
    ll i = 1;
    for(auto & e : vp){
        cord[e] = i;
        i++;
    }
    

    for(long long i = 0; i<n; i++){
        ll vi = cord[v[i]];
        ll prev = query(1, 0, n, 0, vi-1);
        update(1, 0, n, vi, prev+1);
    }

    cout<<query(1, 0, n, 0, n);
 
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