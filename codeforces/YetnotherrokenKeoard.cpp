#include <bits/stdc++.h>

void solve(std::string& str){
    std::vector<std::pair<char, long long>>upper;
    std::vector<std::pair<char, long long>>lower;

    for(long long i = 0; i<str.size(); i++){
        if(str[i] == 'B' || str[i] == 'b'){
            if(str[i] == 'b'){
                if(!lower.empty()){
                    lower.pop_back();
                }
            } else {
                if(!upper.empty()){
                    upper.pop_back();
                }
            }
        } else {
            std::pair<char, long long>p;
            p.first = str[i];
            p.second = i;
            if(std::isupper(str[i])){
                upper.push_back(p);
            } else {
                lower.push_back(p);
            }
        }
    }
    long long i = 0;
    long long k = 0;

    while(i < upper.size() || k < lower.size()){
        if(i < upper.size() && k < lower.size()){
            if(upper[i].second < lower[k].second){
                std::cout<<upper[i].first;
                i++;
            } else {
                std::cout<<lower[k].first;
                k++;
            }
        } else if(i < upper.size()){
            std::cout<<upper[i].first;
            i++;
        } else {
            std::cout<<lower[k].first;
            k++;
        }
    }

    std::cout<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
   std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;
    std::cin.ignore();

    while(t--){
       std::string str;
       std::getline(std::cin, str);
       solve(str);
    }

    return 0;
}