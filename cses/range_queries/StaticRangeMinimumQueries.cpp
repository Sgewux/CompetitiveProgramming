#include <bits/stdc++.h>

const long long N = 2e5+1;
long long t[4*N];

void build(std::vector<long long>& a, long long v, long long l, long long r){
    if(l == r){
        t[v] = a[l];
    } else {
        long long m = (l+r)/2;
        build(a, 2*v, l, m);
        build(a, 2*v +1, m+1, r);
        t[v] = std::min(t[2*v], t[2*v + 1]);
    }
}

long long query(long long v, long long l, long long r, long long ql, long long qr ){
    if(ql > qr){
        return 1e9 + 1;
    } else if(l == ql && r == qr){
        return t[v];
    } else {
        long long m = (l+r)/2;
        long long a = query(2*v, l, m, ql, std::min(m,qr));
        long long b = query(2*v + 1, m+1, r, std::max(m+1,ql), qr);

        return std::min(a,b);
    }
}

void solve(){
    long long n;
    long long q;
    std::cin>>n;
    std::cin>>q;

    std::vector<long long>a(n);

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
    }

    build(a,1,0,n-1);
    
    for(long long i = 0; i<q; i++){
        long long ql;
        long long qr;
        std::cin>>ql;
        std::cin>>qr;

        std::cout<<query(1, 0, n-1, ql-1, qr-1)<<'\n';
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