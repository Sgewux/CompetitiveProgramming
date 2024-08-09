#include <bits/stdc++.h>

const long long N = 1e5+1;
long long t1[4*N];
long long t2[4*N];

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
    long long curr;
    long long ans = 0;
    std::cin>>n;
    std::vector<std::pair<long long, long long>> v(n, {-1,-1});

    for(long long i = 0; i<2*n; i++){
        std::cin>>curr;
        if(v[curr-1].first == -1) {
            v[curr-1].first = i;
        } else if(v[curr-1].second == -1){
            v[curr-1].second = i;
        }
    }

    std::sort(v.begin(), v.end(), std::greater<std::pair<long long,long long>>());

    for(long long i = 0; i<n; i++){
        ans += (query(1,0,2*n,v[i].second+1, 2*n, t2) - query(1,0,2*n,v[i].second+1, 2*n, t1));
        update(1,0,2*n, v[i].first,1,t1);
        update(1,0,2*n,v[i].second,1,t2);
    }

    std::cout<<ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    std::freopen("circlecross.in", "r", stdin);
    std::freopen("circlecross.out", "w", stdout);

    long long t=1;

    while(t--){
        solve();
    }

    return 0;
}