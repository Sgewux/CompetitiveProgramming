#include <bits/stdc++.h>

struct sort_pred{
    bool operator()(const std::pair<long long, long long>& left, const std::pair<long long, long long>& right){
        if(left.second == right.second){
            return left.first < right.first;
        } else {
            return left.second < right.second;
        }
    }
};


void solve(){
    long long n;
    long long x;
    long long y;
    long long curr;
    std::vector<long long>v;
    std::vector<std::pair<long long, long long>>vp;
    std::map<long long, long long> m;
    std::cin>>n;
    std::cin>>x;
    std::cin>>y;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        v.push_back(curr);
        vp.push_back({i, curr % y});
    }

    std::sort(vp.begin(), vp.end(), sort_pred());

    long long ans = 0;
    long long lastSeen = vp[0].second;
    long long i = 0;

    while(i < n){

        if(lastSeen != vp[i].second){
            m.clear();
            lastSeen = vp[i].second;
        }

        long long target = (x - (v[vp[i].first] % x)) % x;

        if(m.count(target)){
            ans += m[target];
        }

        if(m.count(v[vp[i].first] % x)){
            m[v[vp[i].first] % x]++;
        } else {
            m[v[vp[i].first] % x] = 1;
        }

        i++;
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