#include <bits/stdc++.h>

long long solve(std::vector<long long>& p, long long l, long long r){
    
    if(r-l == 1){
        if(p[0] == 1){
            return 0;
        } else {
            return -1;
        }

    }else if(r-l == 2){
        if(std::abs(p[r-1] - p[l]) > 1){
            return -1;
        } else {
            if(p[l] > p[r-1]){
                return 1;
            } else {
                return 0;
            }
        }
    } else {
        long long leftHalf = solve(p, l, (l+r)/2);
        long long rightHalf = solve(p, (l+r)/2, r);

        if(leftHalf == -1 || rightHalf == -1){
            return -1;
        } else {
            long long leftSum = 0;
            long long rightSum = 0;
            long long min = 1e9;
            long long max = -1e9;

            for(long long i = l; i<r; i++){
                min = std::min(min, p[i]);
                max = std::max(max, p[i]);

                if(i < (l+r)/2){
                    leftSum += p[i];
                } else {
                    rightSum += p[i];
                }
            }

            if((max-min) == (r-l-1)){
                return leftSum > rightSum ? rightHalf + leftHalf + 1 : rightHalf + leftHalf;   
            } else {
                return -1;
            }
            
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long curr;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::vector<long long>p;

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            p.push_back(curr);
        }

        std::cout<<solve(p, 0, n)<<'\n';
    }

    return 0;
}