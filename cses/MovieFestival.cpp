#include <bits/stdc++.h>

struct sort_pred{
    bool operator()(const std::pair<long long, long long>& l, const std::pair<long long, long long>& r){
        if(l.first == r.first){
            return l.second < r.second;
        } else {
            return l.first < r.first;
        }
    }
};

long long bsearch(std::vector<std::pair<long long, long long>>& p, long long t){
    long long l =0;
    long long r = p.size()-1;

    while(l<r){
        long long m = (l+r)/2;

        if(p[m].first == t){
            return m;
        } else if(p[m].first < t){
            l = m+1;
        } else if(p[m].first > t){
            r = m-1;
        }
    }

    long long m = (r+l)/2;
    if(p[m].first < t){
        return m+1;
    } else {
        return m;
    }
}

long long solve(long long n, std::vector<std::pair<long long, long long>>& a){
    std::sort(a.begin(), a.end(), sort_pred());

    std::vector<std::pair<long long, long long>>p = {a[0]};
    std::vector<std::pair<long long, long long>>np;

    for(long long i = 1; i<n; i++){
        if(p.back().first != a[i].first){
            p.push_back(a[i]);
        }
    }

    if(p.size() == 1){
        return 1;
    }

    for(long unsigned int i =0; i<p.size(); i++){
        long long upper = bsearch(p, p[i].second);

        np.push_back({upper, i});

    }

    std::sort(np.begin(), np.end(), sort_pred());

    long long ans =0;
    long long idx =0;
    for(auto& i : np){
        if(i.second >= idx){
            ans++;
            idx = i.first;
        }
    }


    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t = 1;
    long long n;
    long long a;
    long long b;

    while(t--){
        std::cin>>n;
        std::vector<std::pair<long long, long long>> p;
        for(long long i = 0; i<n; i++){
            std::cin>>a;
            std::cin>>b;
            p.push_back({a,b});
        }

        std::cout<<solve(n, p)<<'\n';
    }

    return 0;
}