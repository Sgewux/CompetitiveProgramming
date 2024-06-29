#include <bits/stdc++.h>

long long countDamage(long long n, long long m, std::vector<long long>& a, std::vector<long long>& c){
    long long damage = 0;
    for(long long i = 0; i<n; i++){
        damage += a[i]*(m % c[i] == 0 ? m/c[i] : std::floor(m/c[i]));
    }

    return (damage >= 0 ? damage : 1e18);
}

void solve(){
    long long n;
    long long h;
    long long sum = 0;
    std::cin>>h;
    std::cin>>n;

    std::vector<long long> a(n);
    std::vector<long long> c(n);

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
        sum += a[i];
    }

    for(long long i = 0; i<n; i++){
        std::cin>>c[i];
    }

    long long m = 0;
    long long ans = 1e18;
    long long l = 0;
    long long r = 1e18;
    h -= sum;

    while( l < r){
        m = (l+r)/2;
        long long damage = countDamage(n, m,  a, c);

        if(damage > h){
            r = m-1;
        } else if(damage < h){
            l = m+1;
        } else {
            ans = std::min(ans, m+1);
            r = m-1;
        }
    }

    m = (l+r)/2;
    if(countDamage(n,m,a,c) < h){
        m++;
    }

    std::cout<<std::min(ans, m+1)<<'\n';
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