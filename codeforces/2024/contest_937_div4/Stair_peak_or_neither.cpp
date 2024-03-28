#include <bits/stdc++.h>

void solve(){
    long long a;
    long long b;
    long long c;

    std::cin>>a;
    std::cin>>b;
    std::cin>>c;

    if(a<b && b<c){
        std::cout<<"STAIR";
    } else if(a<b && b > c){
        std::cout<<"PEAK";
    } else {
        std::cout<<"NONE";
    }

    std::cout<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;

    while(t--){
        solve();
    }

    return 0;
}