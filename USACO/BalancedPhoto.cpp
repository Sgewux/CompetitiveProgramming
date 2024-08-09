#include <bits/stdc++.h>

const long long N = 1e5+1;
long long t1[4*N];
long long t2[4*N];

void build(std::vector<long long>& a, long long v, long long l, long long r, long long t[]){
    if(l == r){
        t[v] = a[l];
    } else {
        long long m = (l+r)/2;
        build(a, 2*v, l, m, t);
        build(a, 2*v +1, m+1, r, t);
        t[v] = t[2*v] + t[2*v + 1];
    }
}

void update(long long v, long long l, long long r, long long pos, long long newVal, long long t[]){
    if(l == r){
        t[v] += newVal;
    } else {
        long long m = (l+r)/2;
        if(pos <= m){
            update(2*v, l, m, pos, newVal, t);
        } else {
            update(2*v + 1, m+1, r, pos, newVal, t);
        }

        t[v] = t[2*v] + t[2*v + 1];
    }
}

long long query(long long v, long long l, long long r, long long ql, long long qr, long long t[]){
    if(ql > qr){
        return 0;
    } else if(l == ql && r == qr){
        return t[v];
    } else {
        long long m = (l+r)/2;
        long long a = query(2*v, l, m, ql, std::min(m,qr), t);
        long long b = query(2*v + 1, m+1, r, std::max(m+1,ql), qr, t);

        return a + b;
    }
}

void solve(){
    long long n;
    std::cin>>n;

    std::map<long long, long long>cord;
    std::map<long long, long long>l;
    std::vector<long long>h(n);
    std::vector<long long>v(n);

    for(long long i = 0; i<n; i++){
        std::cin>>h[i];
        v[i] = h[i];
    }

    std::sort(v.begin(), v.end());
    
    for(long long i = 0; i<n; i++){
        cord[v[i]] = i+1;
    }

    for(long long i = 0; i<n; i++){
        l[h[i]] = query(1,0,n,cord[h[i]]+1,n,t1);
        update(1,0,n,cord[h[i]],1,t1);
    }

    std::reverse(h.begin(), h.end());
    long long ans = 0;

    for(long long i = 0; i<n; i++){
        long long li = l[h[i]];
        long long ri = query(1,0,n,cord[h[i]]+1,n,t2);
        update(1,0,n,cord[h[i]],1,t2);

        if(std::max(li,ri) > 2* std::min(li,ri)) ans++;

    }

    std::cout<<ans;

}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::freopen("bphoto.in", "r", stdin);
    std::freopen("bphoto.out", "w", stdout);

    long long t = 1;

    while(t--){
        solve();
    }

    return 0;
}