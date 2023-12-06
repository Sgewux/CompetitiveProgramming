#include <bits/stdc++.h>

void solve(std::vector<long long>& s, long long max, long long second){
    for(auto i : s){
        if(i == max){
            std::cout<< i - second << ' ';
        } else {
            std::cout<< i - max << ' ';
        }
    }

    std::cout<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long curr;
    long long max;
    long long second;

    std::cin>>t;

    while(t--){
        max=-1;
        second=-1;
        std::cin>>n;
        std::vector<long long> s;

        for(long long i=0;i<n;i++){
            std::cin>>curr;
            s.push_back(curr);

            if(curr > max){
                second = max;
                max = curr;
            } else {
                second = std::max(second, curr);
            }
        }

        solve(s, max, second);
        
    }
    
    return 0;
}