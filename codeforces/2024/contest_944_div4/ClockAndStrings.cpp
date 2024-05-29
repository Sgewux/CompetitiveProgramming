#include <bits/stdc++.h>

void solve(){
    long long a;
    long long b;
    long long c;
    long long d;

    std::cin>>a;
    std::cin>>b;
    std::cin>>c;
    std::cin>>d;

    if(c < std::max(a,b) && c>std::min(a,b)){
        if(d < std::max(a,b) && d>std::min(a,b)){
            std::cout<<"NO"<<'\n';
        } else {
            std::cout<<"YES"<<'\n';
        }
    } else {
        if(!(d < std::max(a,b) && d>std::min(a,b))){
            std::cout<<"NO"<< '\n';
        } else {
            std::cout<<"YES"<< '\n';
        }
    }
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