#include <bits/stdc++.h>
const long long N = 1e5+1;
long long t[4*N];

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
        t[v] += newVal;
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
    std::cin>>n;
    std::vector<long long> freq(n+1,0);
    std::vector<long long> a(n);
    std::vector<long long> inv(n+1);
    build(freq, 1, 0, n);

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
        inv[a[i]] += query(1,0,n,a[i]+1,n);
        update(1,0,n,a[i],1);
    }
    long long totalInv = 0;
    for(long long i = 0; i<n+1; i++){
        totalInv += inv[i];
    }
    std::vector<long long>ans(n);

    for(long long i = n-1; i>=0; i--){
        ans[i] = totalInv - inv[i];
        totalInv -= inv[i];
    }

    for(long long i = 0; i<n; i++){
        std::cout<<ans[i]<<'\n';
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::freopen("haircut.in", "r", stdin);
    std::freopen("haircut.out", "w", stdout);

    long long t=1;

    while(t--){
        solve();
    }

    return 0;
}