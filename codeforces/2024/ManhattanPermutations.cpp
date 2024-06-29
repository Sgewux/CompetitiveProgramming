#include <bits/stdc++.h>

void solve(){
    long long n;
    long long k;
    std::cin>>n;
    std::cin>>k;

    std::vector<long long> v(n);

    for(long long i = 1; i<n+1; i++){
        v[i-1] = i;
    }

    if(k%2 != 0){
        std::cout<<"NO"<<'\n';
        return;
    }

    k /= 2;
    long long l = 0;
    long long r = n-1;
    long long minus = 1;

    while(l < r && k > 0){
        if(k <= n-minus){
            std::swap(v[l], v[l + k]);
            k = 0;
        } else {
            k -= std::abs(v[l]-v[r]);
            std::swap(v[l], v[r]);
            l++;
            r--;
        }

        minus += 2;
    }

    if( k == 0){
        std::cout<<"YES"<< '\n';

        for(long long i = 0; i<n; i++){
            std::cout<< v[i] << ' ';
        }

        std::cout<< '\n';
    } else {
        std::cout<< "NO" <<'\n';
    }
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