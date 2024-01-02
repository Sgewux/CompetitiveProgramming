#include <bits/stdc++.h>

void solve(long long n, std::string_view str){
    long long diff = 0;

    for(long long i = 0; i<std::floor(n/2); i++){
        if(str[i] != str[n-(1+i)]){
            diff++;
        }
    }

    long long max = n-diff;

    for(long long i = 0; i<n+1; i++){
        if(diff <= i && i <= max){
            if(n%2 == 0){
                if((i-diff)%2 == 0){
                    std::cout<<'1';
                } else {
                    std::cout<<'0';
                }
            } else {
                std::cout<<'1';
            }
        } else {
            std::cout<<'0';
        }
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