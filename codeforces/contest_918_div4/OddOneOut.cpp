#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;

    while(t--){
        std::unordered_map<long long, long long> occurrence;
        long long curr;

        for(long long i = 0; i < 3; i++){
            std::cin>>curr;

            if(occurrence.count(curr)){
                occurrence[curr]++;
            } else {
                occurrence[curr] = 1;
            }

       }

        for(auto i : occurrence){
            if(i.second == 1){
                std::cout<<i.first<<'\n';
            }
        }
 
    }

    return 0;
}