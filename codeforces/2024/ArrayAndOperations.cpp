#include <bits/stdc++.h>

long long solve(long long n, long long k, std::vector<long long>& a){
    long long ans = 0;
    std::unordered_set<long long> marked;
    for(long long i = 0; i<k; i++){
        if(!marked.count(i)){
            std::vector<long long> different;
            std::vector<long long>equal;
            for(long long j = k; j<2*k; j++){
                if(!marked.count(j)){
                    if(a[i] != a[j]){
                        different.push_back(j);
                    } else {
                        equal.push_back(j);
                    }
                }
            }

            if(!different.empty()){
                marked.insert(different[0]);
            } else {
                ans++;
                marked.insert(equal[0]);
            }

            marked.insert(i);
        }
    }

    for(long long i = 2*k; i<n; i++){
        ans += a[i];
    }

    return ans;
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
        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            a.push_back(curr);
        }

        std::sort(a.begin(), a.end(), std::greater<>());
        std::cout<<solve(n,k,a)<<'\n';
    }

    return 0;
}