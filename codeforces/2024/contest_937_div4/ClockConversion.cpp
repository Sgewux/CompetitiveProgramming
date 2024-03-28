#include <bits/stdc++.h>

void solve(){
    std::string s;
    std::getline(std::cin, s);

    std::string hour = "";
    for(long long i = 0; i<2; i++){
        hour += s[i];
    }
    int hourNum = std::stoi(hour);


    if(hourNum != 12 && hourNum != 0){
        if(hourNum%12 < 10){
            std::cout<<'0';
        }
        std::cout<<hourNum%12;
    } else {
        std::cout<<12;
    }

    std::cout<<":"<<s.substr(3,5);

    hourNum >= 12 ? std::cout<<" PM" : std::cout<<" AM";
    
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
        solve();
    }

    return 0;
}