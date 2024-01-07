#include <bits/stdc++.h>

void solve(std::vector<long long>& a, std::vector<long long>& x){
    for(long long ai : a){
        for(long long xi : x){
            long long power = std::pow(2, xi);
            if(ai % power  == 0){
                ai += std::pow(2, xi-1);
            }
        }

        std::cout<<ai<<' ';
    }

    std::cout<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long q;
    long long curr;
    std::vector<long long>a;
    std::vector<long long >x;
    std::cin>>t;

    while(t--){
        a.clear();
        x.clear();
        std::cin>>n;
        std::cin>>q;

        for(long long i = 0; i<n; i++){
           std::cin>>curr;
           a.push_back(curr);
        }
        long long lastSeen = 1e9;
        for(long long i = 0; i<q; i++){
            std::cin>>curr;
            if(curr < lastSeen){
                lastSeen = curr;
                x.push_back(curr);
            }   
        }

        solve(a, x);
    }

    return 0;
}