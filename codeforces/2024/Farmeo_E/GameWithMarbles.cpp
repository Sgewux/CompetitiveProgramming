#include <bits/stdc++.h>

struct sort_pred{
    bool operator()(std::pair<long long, long long>& left, std::pair<long long, long long>& right){
        return left.second < right.second;
    }
};

void solve(){
    long long n;
    long long curr;
    std::cin>>n;
    std::vector<long long>a(n);
    std::vector<long long>b(n);
    std::vector<std::pair<long long, long long>>p;

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
    }

    for(long long i = 0; i<n; i++){
        std::cin>>b[i];
        p.push_back({i,a[i] + b[i]});
    }


    std::sort(p.begin(), p.end(), sort_pred());
    long long ans = 0;

    for(long long i = 0; i<n; i++){
        if(i%2 == 0){
            ans += a[p.back().first]-1;
        } else {
            ans -= b[p.back().first]-1;
        }
        p.pop_back();
    }

    std::cout<< ans <<'\n';
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