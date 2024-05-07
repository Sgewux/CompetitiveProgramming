#include <bits/stdc++.h>

long long lower(long long t, std::vector<long long>& v){
    long long l = 0;
    long long r = v.size() - 1;
    long long m;

    while(l<r){
        m = (l+r)/2;

        if(v[m] == t){
            return m-1;
        } else if(v[m] > t){
            r = m-1;
        } else if(v[m] < t){
            l = m+1;
        }
    }

    m = (l+r)/2;

    if(v[m] < t){
        return m;
    } else {
        return m-1;
    }
}

void solve(){
    long long n;
    long long ans = 0;
    std::vector<long long> good;
    std::cin>>n;
    std::vector<long long>a(n);

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
    }

    for(long long i = 0; i<n; i++){
        if(a[i] < i+1){
            if(good.size() >= 1){
                ans += lower(a[i], good) + 1;
            }
            good.push_back(i+1);
        }
    }

    std::cout<<ans<<'\n';
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