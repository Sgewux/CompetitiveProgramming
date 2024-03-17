#include <bits/stdc++.h>

long long bSearch(long long l, long long t, std::vector<long long>& p){
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

void solve(){
    long long n;
    long long k;
    long long curr;
    long long ans = 0;

    std::cin>>n;
    std::cin>>k;

    std::vector<long long>a;
    std::vector<long long>p(n+1, 0);
    std::vector<long long>h;
    std::set<long long>gaps;


    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        a.push_back(curr);
        p[i+1] = p[i] + curr;
    }

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        h.push_back(curr);

        if(i > 0 && (h[i-1]%curr != 0)){
            gaps.insert(i);
        }
    }

    long long l = 0;
    for(long long r = 0; r<n; r++){
        if(gaps.count(r)){
            l = r;
        }

        if(p[r+1] - p[l] <= k){
            ans = std::max(ans, (r+1)-l);
        } else {
            long long t = p[r+1] - k;
            ans = std::max(ans, (r+1) - bSearch(l, t, p) );
        }
    }

    std::cout<<ans<<'\n';
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