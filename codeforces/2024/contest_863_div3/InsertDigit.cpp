#include <bits/stdc++.h>

void solve(long long n, std::string_view str, long long d){
    long long i = 0;
    bool done = false;
    std::vector<long long>digits(n);
    for(char c : str){
        int digit = c-48;
        if(digit < d && !done){
            std::cout<<d<<digit;
            done = true;
        } else {
            std::cout<<digit;
        }
    }

    if(!done){
        std::cout<<d;
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long d;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::cin>>d;
        std::cin.ignore();
        std::string str;
        std::getline(std::cin, str);

       solve(n,str,d);
       std::cout<<'\n';
    }

    return 0;
}