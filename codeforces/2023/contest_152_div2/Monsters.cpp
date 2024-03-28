#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>

void solve(std::vector<long long>& zeros, std::vector<std::pair<long long, long long>>& other){

    for(auto num : zeros){
        std::cout<<num<<' ';
    }

    for(auto num : other){
        std::cout<<num.first<<' ';
    }

    std::cout<<std::endl;
}

struct sort_pred{
    bool operator()(const std::pair<long long, long long>& left, const std::pair<long long, long long>& right){
        if(left.second == right.second){
            return left.first < right.first;
        } else { 
            return left.second > right.second;
        }
    }
};


int main(){
    long long t;
    long long n;
    long long k;
    long long num;
    std::cin>>t;
    for(long long j = 0; j < t; j++){
        std::cin>>n;
        std::cin>>k;

        std::vector<long long> zeros;
        std::vector<std::pair<long long, long long>> other;

        for(long long i = 0; i < n; i++){
            std::cin>>num;
            if(num%k == 0){
                zeros.push_back(i+1);
            } else {
                std::pair<long long, long long> p(i+1, num%k);
                other.push_back(p);
            }
        }
        std::sort(other.begin(), other.end(), sort_pred());
        solve(zeros, other);
    }
    return 0;

}