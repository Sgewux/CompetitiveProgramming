#include <bits/stdc++.h>

long long solve(long long k, std::vector<long long>& v){
    
    if(k == 2){
        for(long long i : v){
            if(i%2 == 0){
                return 0;
            }
        }
        return 1;
    } else if (k == 3 || k == 5){
        long long ans = 1e9;
        for(long long i : v){
            long long curr = 0;
            while(!((i % k) == 0)){
                curr++;
                i++;
            }

            ans = std::min(ans, curr);
        }

        return ans;

    } else {
        
        long long ans = 2;
        long long twos = 0;
        for(long long i : v){
            if(i%2 == 0){
                twos++;
                if(twos >= 2 || i%4 == 0){
                    return 0;
                }
            }

            if(i > 8){
                ans = std::min(ans, 12-i);
            } else if(i > 4){
                ans = std::min(ans, 8-i);
            } else {
                ans = std::min(ans, 4-i);
            }

        }

        return twos == 1 ? 1 : ans;
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long k;
    std::vector<long long> v;
    long long curr;
    std::cin>>t;

    while(t--){
        v.clear();
        std::cin>>n;
        std::cin>>k;

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            v.push_back(curr);
        }

        std::cout<<solve(k, v)<<'\n';
    
    }

    return 0;
}