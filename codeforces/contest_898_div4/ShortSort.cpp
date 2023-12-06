#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;


    std::string str;
    std::getline(std::cin,str);

    for(long long i =  0; i<t; i++){
        std::getline(std::cin,str);
        if(str == "bac" || str=="cba" || str=="acb" || str=="abc"){
            std::cout<<"YES"<<'\n';
        } else {
            std::cout<<"NO"<<'\n';
        }
    }
    
    return 0;
}