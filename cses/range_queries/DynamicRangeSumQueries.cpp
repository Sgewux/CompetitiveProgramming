#include <bits/stdc++.h>

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
    long long n;
    long long q;

    std::cin>>n;
    std::cin>>q;
    std::vector<long long> a(n);

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
    }

    build(a,1,0,n-1);

    int qtype;
    long long k;
    long long u;

    for(long long i = 0; i<q; i++){
        std::cin>>qtype;
        std::cin>>k;
        std::cin>>u;

        if(qtype == 1){
            update(1,0,n-1,k-1,u);
        } else {
            std::cout<<query(1,0,n-1,k-1,u-1)<<'\n';
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