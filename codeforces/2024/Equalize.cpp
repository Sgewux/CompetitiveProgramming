#include <bits/stdc++.h>

long long findCoverage(long long t, long long s, std::vector<long long>&a){
    long long m;
    long long e = a.size()-1;

    while(s<e){
        m = (s+e)/2;

        if(a[m] == t){
            return m;
        } else if(a[m] < t){
            s=m+1;
        } else if(a[m] > t){
            e=m-1;
        }
    }

    m = (s+e)/2;

    if(a[m] <= t){
        return m;
    } else {
        return m-1;
    }
}

long long solve(long long n, std::vector<long long>& a){
    std::sort(a.begin(), a.end());
    long long ans = 1;

    for(long long i = 0; i<a.size(); i++){
        ans = std::max(ans, findCoverage(n-1+a[i], i, a)-i+1);
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
    std::cin>>t;

    while(t--){
        std::set<long long>s;
        std::cin>>n;
        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            s.insert(curr);
        }
        std::vector<long long>a(s.begin(), s.end());
        std::cout<<solve(n,a)<<'\n';
    }

    return 0;
}