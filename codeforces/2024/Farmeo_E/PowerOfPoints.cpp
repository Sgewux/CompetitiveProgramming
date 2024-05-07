#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin>>n;
    std::vector<long long>x(n);
    std::vector<long long>xc(n);
    std::map<long long, long long> f;

    for(long long i = 0; i<n; i++){
        std::cin>>x[i];
        xc[i] = x[i];
        f[x[i]] = 0;
    }

    std::sort(x.begin(), x.end());

    long long acc = 0;
    long long lastSeen = x[0];
    for(long long i = 0; i<n; i++){
        if(x[i] != lastSeen){
            acc += (i)*(std::abs(x[i] - lastSeen));
            f[x[i]] += acc;
        }

        lastSeen = x[i];
    }

    acc = 0;
    lastSeen = x.back();
    for(long long i = n-1; i>=0; i--){
        if(x[i] != lastSeen){
            acc += (n-i-1)*(std::abs(x[i] - lastSeen));
            f[x[i]] += acc;
        }

        lastSeen = x[i];
    }
    
    for(long long i = 0; i<n; i++){
        std::cout<<f[xc[i]] + n<<' ';
    }

    std::cout<<'\n';
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