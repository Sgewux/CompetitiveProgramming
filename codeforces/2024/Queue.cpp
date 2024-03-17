#include <bits/stdc++.h>

long long bSearch(long long t, std::vector<long long>& p){
    long long l = 0;
    long long r = p.size()-1;
    long long m;

    while(l < r){
        m = (l+r)/2;
        if(p[m] == t){
            return m;
        } else if(p[m] < t){
            l = m+1;
        } else if(p[m] > t){
            r = m-1;
        }
    }

    m = (l + r)/2;

    if(p[m] < t){
        return m+1;
    } else {
        return m;
    }
}

long long solve(long long n, std::vector<long long>& times){
    std::vector<long long>p;
    std::unordered_set<long long> choosen;
    p.push_back(0);
    bool limitReached = false;
    
    long long i = 0;
    while(!limitReached){
        long long j = bSearch(p[i], times);

        if(choosen.count(j)){
            j++;
        }

        if(j < n){
            p.push_back(p[i] + times[j]);
            choosen.insert(j);
            i++;
        } else {
            limitReached = true;
        }
    }

    return p.size() - 1;

}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t = 1;
    long long n;
    long long curr;

    while(t--){
        std::cin>>n;
        std::vector<long long> times;

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            times.push_back(curr);
        }

        std::sort(times.begin(), times.end());

        std::cout<<solve(n, times)<<'\n';
        
    }

    return 0;
}