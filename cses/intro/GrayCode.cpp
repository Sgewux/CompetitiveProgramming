#include<iostream>
#include<vector>
#include<string>
#include<cmath>

std::vector<std::string> solve(long long n){
    std::vector<std::string> v;

    if(n == 1){
        v.push_back("0");
        v.push_back("1");

        return v;
    } else {
        std::vector<std::string> prev = solve(n-1);

        for(long long i = 0; i < std::pow(2, n-1); i++){
            v.push_back("0" + prev[i]);
        }

        for(long long i =  std::pow(2, n-1) - 1; i >= 0; i--){
            v.push_back("1" + prev[i]);
        }

        return  v;

    }
}

int main(){
    long long n;
    std::cin>>n;

    for(auto s : solve(n)){
        std::cout<<s<<'\n';
    }

    return 0;
}