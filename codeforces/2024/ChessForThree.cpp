#include <bits/stdc++.h>

void solve(){
    long long p1;
    long long p2;
    long long p3;
    long long diff;

    std::cin>>p1;
    std::cin>>p2;
    std::cin>>p3;

    diff = p3-p2;
    if( (diff%2 == 0 && p1%2 == 0 )|| (diff%2 != 0 && p1%2 != 0)){
        if(p1<=diff){
            std::cout << p1 + p2;
        } else {
            std::cout << p1 + p2 - (p1-diff)/2;
        }
    } else {
        std::cout<<-1;
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