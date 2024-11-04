#include <bits/stdc++.h>
#define ll long long

using namespace std;

const long long N = 2e5+1;
long long t[4*N];

/*
v: Current Segment Tree node (1 in first call)
l: Current left boundary (0 in first call)
r: Current right boundary (n-1 in first call)
*/

void build(std::vector<long long>& a, long long v, long long l, long long r){
    if(l == r){
        t[v] = a[l];
    } else {
        long long m = (l+r)/2;
        build(a, 2*v, l, m);
        build(a, 2*v +1, m+1, r);
        t[v] = t[2*v] + t[2*v + 1];
    }
}

void update(long long v, long long l, long long r, long long pos, long long newVal){
    if(l == r){
        t[v] = newVal;
    } else {
        long long m = (l+r)/2;
        if(pos <= m){
            update(2*v, l, m, pos, newVal);
        } else {
            update(2*v + 1, m+1, r, pos, newVal);
        }

        t[v] = t[2*v] + t[2*v + 1];
    }
}

long long query(long long v, long long l, long long r, long long ql, long long qr){
    if(ql > qr){
        return 0;
    } else if(l == ql && r == qr){
        return t[v];
    } else {
        long long m = (l+r)/2;
        long long a = query(2*v, l, m, ql, std::min(m,qr));
        long long b = query(2*v + 1, m+1, r, std::max(m+1,ql), qr);

        return a + b;
    }
}

void solve(){
    ll n; ll q;
    cin>>n>>q;
    char qt; ll a; ll b;
    vector<ll>c(n,0);
    build(c, 1, 0, n-1);
    
    while(q--){
        cin>>qt;
        if(qt == '?'){
            cin>>a>>b;
            a--; b--;
            if(a > b) swap(a,b);
            
            if(min(query(1,0,n-1,a,b), query(1,0,n-1,b,n-1) + query(1,0,n-1,0,a)) == 0){
                cout<<"possible"<<'\n';
            } else {
                cout<<"impossible"<<'\n';
            }

        } else if(qt == '-'){
            cin>>a;
            update(1,0,n-1,a-1,1);
        } else if(qt == '+'){
            cin>>a;
            update(1,0,n-1,a-1,0);
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t = 1;

    while(t--){
        solve();
    }

    return 0;
}