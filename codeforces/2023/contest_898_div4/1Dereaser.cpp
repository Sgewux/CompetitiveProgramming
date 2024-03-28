#include <bits/stdc++.h>

long long solve(std::vector<long long>& idx, long long n, long long k){
    long long count = 0;
    if(idx.size() == 0){
        return 0;
    } else if(n == k || idx.size() == 1){
        return 1;
    } else {
        long long i = 0;
        long long j = 0;
        
        while(j<idx.size()){
            if( (idx[j] - idx[i])+1 <= k ){
                j++;
            } else {
                count++;
                i=j;
            }
        }

        count++;

        return count;
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long k;
    std::string curr;
    std::cin>>t;
    

    while(t--){
        std::cin>>n;
        std::cin>>k;
        std::vector<long long> idx;
        std::getline(std::cin, curr);
        std::getline(std::cin, curr);

        for(long long i = 0; i<n; i++){
            if(curr.at(i) == 'B'){
                idx.push_back(i);
            }
        }

        std::cout<<solve(idx, n, k)<<'\n';

    }
    
    return 0;
}