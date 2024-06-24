#include <bits/stdc++.h>

void solve(){
    long long n;
    long long m;
    std::cin>>n;
    std::cin>>m;

    std::vector<long long> r(m);
    std::vector<std::vector<long long>> a(n);

    for(long long i = 0; i<n; i++){
        for(long long j = 0; j<m; j++){
            std::cin>>r[j];
        }
        a[i] = r;
    }

    for(long long i = 0; i<n; i++){
        for(long long j = 0; j<m; j++){
            long long bigN = -1;
            if(j+1 < m){
                bigN = std::max(bigN, a[i][j+1]);
            }

            if(j-1 >= 0){
                bigN = std::max(bigN, a[i][j-1]);
            }

            if(i + 1 < n){
                bigN = std::max(bigN, a[i+1][j]);
            }

            if(i - 1 >= 0){
                bigN = std::max(bigN, a[i-1][j]);
            }

            if(a[i][j] > bigN){
                a[i][j] = bigN;
            }
        }
    }

    for(long long i = 0; i<n; i++){
        for(long long j = 0; j<m; j++){
            std::cout<<a[i][j] << ' ';
        }
        std::cout<<'\n';
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