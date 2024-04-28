#include <bits/stdc++.h>

void solve(){
    long long n;
    long long m;
    long long curr;
    long long digits = 0;
    std::vector<long long> zeros;

    std::cin>>n;
    std::cin>>m;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        digits += std::to_string(curr).length();
        long long j = 9;
        while(j>=0){
            if(curr % (int)std::pow(10,j) == 0){
                zeros.push_back(j);
                break;
            }

            j--;
        }
    }

    std::sort(zeros.begin(), zeros.end(), std::greater<long long>());

    for(long long i = 0; i<zeros.size(); i++){
        if(i%2 == 0){
            digits-=zeros[i];
        }
    }

    std::cout<< ((digits-1) >= m ? "Sasha" : "Anna") << '\n';
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