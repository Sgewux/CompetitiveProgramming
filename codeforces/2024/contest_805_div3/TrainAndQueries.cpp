#include <bits/stdc++.h>

struct sort_pred {
    bool operator()(std::pair<long long, long long>& l, std::pair<long long, long long>& r){
        if(l.first == r.first){
            return l.second < r.second;
        } else {
            return l.first < r.first;
        }
    }
};

long long findRightMost(std::vector<std::pair<long long, long long>>& v, long long t){
    long long l = 0;
    long long r = v.size()-1;
    long long ans = -1;

    while(l <= r){
        long long m = (l+r)/2;

        if(v[m].first < t){
            l = m+1;
        } else if(v[m].first > t){
            r = m-1;
        } else {
            l = m+1;
            ans = std::max(ans, m);
        }
    }

    return ans;
}

long long findLeftMost(std::vector<std::pair<long long, long long>>& v, long long t){
    long long l = 0;
    long long r = v.size()-1;
    long long ans = 1e9;

    while(l <= r){
        long long m = (l+r)/2;

        if(v[m].first < t){
            l = m+1;
        } else if(v[m].first > t){
            r = m-1;
        } else {
            r = m-1;
            ans = std::min(ans, m);
        }
    }

    return ans;
}

void solve(){
    long long n;
    long long k;
    std::cin>>n;
    std::cin>>k;
    std::vector<std::pair<long long, long long>> v(n);
    std::set<long long> s;
    long long curr;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        v[i] = {curr,i};
        s.insert(curr);
    }

    std::sort(v.begin(), v.end(), sort_pred());

    long long a;
    long long b;
    
    for(long long i = 0; i<k; i++){
        std::cin>>a;
        std::cin>>b;

        if(s.count(a) && s.count(b)){
            long long l = findLeftMost(v, a);
            long long r = findRightMost(v, b);

            std::cout<<(v[l].second < v[r].second ? "YES" : "NO")<<'\n';

        } else {
            std::cout<<"NO"<<'\n';
        }
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