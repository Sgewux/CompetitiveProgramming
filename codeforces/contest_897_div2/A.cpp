#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>


struct sort_pred{
    bool operator()(const std::pair<long long, long long>& left, const std::pair<long long, long long>& right){

        return left.first > right.first;
    }
};

std::vector<long long> solve(std::vector<std::pair<long long, long long>>& a, long long n){
    std::sort(a.begin(), a.end(), sort_pred());
    std::vector<long long> ans(n, 0);

    for(long long i = 0; i < n; i++){
        ans[a[i].second] = i+1;
    }

    return ans;
}



int main(){
    long long t;
    long long n;
    long long a_i;
    std::cin>>t;
    for(long long j = 0; j < t; j++){\
        std::vector<std::pair<long long, long long>> a;
        std::cin>>n;
        for(long long i = 0; i<n; i++){
            std::cin>>a_i;
            std::pair<long long, long long> p(a_i,i);
            a.push_back(p);
        }

        std::vector<long long> ans;
        ans = solve(a, n);
        for(auto e : ans){
            std::cout<<e<< " ";
        }

        std::cout<<'\n';
    }

    return 0;
}