#include <bits/stdc++.h>


struct sort_pred{
    long long k;
    
    sort_pred(long long k){
        this->k = k;
    }

    bool operator()(long long left, long long right){
        if(left % this->k == right % this->k){
            return left < right;
        } else {
            return left % this->k < right % this->k;
        }
    }
};


void solve(){
    long long n;
    long long k;
    std::cin>>n;
    std::cin>>k;
    std::vector<long long> a(n);
    std::map<long long, long long> m;

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
        m[a[i]%k]++;
    }

    long long oddMod;
    long long oddCnt = 0;

    for(auto& p : m){
        if(p.second % 2 != 0){
            oddCnt++;
            oddMod = p.first;
        }
    }

    if((n%2 == 0 && oddCnt != 0) || (n%2 != 0 && oddCnt != 1)){
        std::cout<<-1<<'\n';
    
    } else {
        long long ans = 0;
        std::vector<long long> odds;
        std::vector<long long> evens;

        for(long long i = 0; i<n; i++){
            if(oddCnt>0 && a[i]%k == oddMod){
                odds.push_back(a[i]);
            } else {
                evens.push_back(a[i]);
            }
        }

        std::sort(evens.begin(), evens.end(), sort_pred(k));
        std::sort(odds.begin(), odds.end(), sort_pred(k));

        if(evens.size() > 1){
            for(long long i = 0; i<evens.size() - 1; i+=2){
                ans += std::abs(evens[i] - evens[i+1])/k;
            }
        }

        if(odds.size() >= 3){
            //Odd list size is always odd
            long long oddSum = 0;

            for(long long i = 0; i<odds.size()-1; i+=2){
                oddSum += std::abs(odds[i] - odds[i+1])/k;
            }

            long long toAdd = oddSum;

            for(long long i = odds.size()-2; i>=0; i--){
                if(i%2 != 0){
                    oddSum -= std::abs(odds[i] - odds[i-1])/k;
                    oddSum += std::abs(odds[i-1] - odds[i+1])/k;
                } else {
                    oddSum -= std::abs(odds[i] - odds[i+2])/k;
                    oddSum += std::abs(odds[i+1] - odds[i+2])/k;
                }

                toAdd = std::min(toAdd, oddSum);
            }

            ans += toAdd;
        }

        std::cout<<ans<<'\n';
    }
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