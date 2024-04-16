    #include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    std::vector<long long> x;
    std::vector<long long> y = {0};
    std::cin>>n;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        x.push_back(curr);
    }

    for(long long i = 1; i<n; i++){
        long long prev = x[i-1] ^ y[i-1];
        y.push_back(prev ^ (prev & x[i]));
        std::cout<<y[i-1]<<" ";
    }

    std::cout<<y[n-1]<<'\n';
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