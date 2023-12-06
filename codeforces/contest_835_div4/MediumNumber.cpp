#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    long long t;
    long long a;
    long long b;
    long long c;
    std::cin>>t;

    while(t--){
       std::vector<long long> abc;
       std::cin>>a;
       std::cin>>b;
       std::cin>>c;
       abc.push_back(a);
       abc.push_back(b);
       abc.push_back(c);
       std::sort(abc.begin(), abc.end());
       std::cout<<abc[1]<<'\n';

    }  
    return 0;
}