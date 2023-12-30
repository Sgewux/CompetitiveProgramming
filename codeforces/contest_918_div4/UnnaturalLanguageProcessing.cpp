#include <bits/stdc++.h>

void solve(long long n, std::string_view str){
    std::unordered_set<char> v = {'a', 'e'};
    std::unordered_set<char> c = {'b', 'c', 'd'};
    long long i = 0;    

    while(i < n-1){
        if(v.count(str[i])){
            std::cout<<str[i];
        } else if(c.count(str[i]) && c.count(str[i+1])) {       
            std::cout<<str[i];
    
        } else {
            if(i != 0){
                std::cout<<'.';
            }
            std::cout<<str[i];
        }

        i++;
    }

    if(i < n){
        std::cout<<str[i];
    }


    std::cout<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    std::string str;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::cin.ignore();
        std::getline(std::cin, str);

        solve(n, str);
    }

    return 0;
}