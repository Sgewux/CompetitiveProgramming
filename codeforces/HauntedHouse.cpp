#include <bits/stdc++.h>

void solve(std::string str){
    std::reverse(str.begin(), str.end());
    long long oneCount = 0;
    long long acc = 0;

    for(char c : str){
        if(c == '1'){
            oneCount++;
        } else {
            acc += oneCount;
            std::cout<<acc<<' ';
        }
    }

    for(long long i = 0; i<oneCount; i++){
        std::cout<<"-1"<<' ';
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

        solve(str);
    }

    return 0;
}