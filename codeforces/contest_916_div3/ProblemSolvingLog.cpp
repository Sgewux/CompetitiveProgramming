#include <bits/stdc++.h>

long long solve(std::string str){
    std::unordered_map<char, long long> c; //char, occurence
    for(char i : str){
        if(c.count(i)){
            c[i]++;
        } else {
            c[i] = 1;
        }
    }

    long long solved = 0;

    for(auto i : c){
        if(i.second >= (int(i.first) - 64)){
            solved++;
        }
    }

    return solved;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    std::string curr;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::cin.ignore();
        std::getline(std::cin, curr);

        std::cout<<solve(curr)<<'\n';
    }

    return 0;
}