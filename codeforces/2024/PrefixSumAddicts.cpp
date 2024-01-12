#include <bits/stdc++.h>

void solve(long long n, long long k, std::vector<long long>& a){
    long long lastSeen = 2e9 + 1;


    
    for(long long i = k-1; i > 0; i--){
        if(a[i] - a[i-1] <= lastSeen){
            lastSeen = a[i]-a[i-1];
        } else {
            std::cout<<"NO";
            return;
        }
    }

    if(a[0] % (n-(k-1)) == 0){
        if(a[0]/(n-(k-1)) <= lastSeen){
            std::cout<<"YES";
            return;
        }
    } else {
        if(a[0] > 0){
            if(std::floor(a[0]/(n-(k-1))) + 1 <= lastSeen){
                std::cout<<"YES";
                return;
            }
        } else {
            if(std::floor(a[0]/(n-(k-1))) <= lastSeen){
                std::cout<<"YES";
                return;
            }
        }
    }

    std::cout<<"NO";

}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long k;
    long long curr;
    std::cin>>t;

    while(t--){
        std::vector<long long>a;
        std::cin>>n;
        std::cin>>k;

        for(long long i = 0; i<k; i++){
            std::cin>>curr;
            a.push_back(curr);
        }

        solve(n, k, a);
        std::cout<<'\n';
    }

    return 0;
}