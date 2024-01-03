#include <bits/stdc++.h>

std::unordered_set<long long> getDivisors(long long n){
    std::unordered_set<long long> k = {1,n};
    for(long long i = 2; i <= std::floor(n/2); i++){
        if(n%i == 0){
            if(k.count(n/i) || k.count(i)){
                break;
            } else {
                k.insert(i);
                k.insert(n/i);
            }
        }
    }

    return k;
}

long long solve(std::vector<long long>& v, long long n, long long min, long long sum){
    long long ans = 1e9;
    std::unordered_set<long long> divisors = getDivisors(sum);
    for(long long d : divisors){
        if((sum/d <= n) && (d >= min)){
            long long thickness = -1;
            long long currSum = 0;
            long long currThickness = 0;
            long long i = 0;

            while(i<n){
                if(currSum + v[i] <= d){
                    currSum+=v[i];
                    currThickness++;

                    if(currSum == d){
                        thickness = std::max(thickness, currThickness);
                        currThickness = 0;
                        currSum = 0;
                    }

                    i++;
                    
                } else {
                    thickness = 1e9;
                    break;
                }
            }

            ans = std::min(ans, thickness);
        }
    }

    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long curr;
    long long min;
    long long sum;
    std::vector<long long> v;
    std::cin>>t;

    while(t--){
        min = 1e9;
        sum = 0;
        v.clear();
        std::cin>>n;

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            sum+=curr;
            min = std::min(min, curr);
            v.push_back(curr);
        }

        std::cout<<solve(v,n,min,sum)<<'\n';
    }

    return 0;
}