#include <bits/stdc++.h>

void solve(){
    std::unordered_set<long long>x;
    std::unordered_set<long long>y;
    long long xi;
    long long yi;

    for(long long i = 0; i<4; i++){
        std::cin>>xi;
        std::cin>>yi;
        x.insert(xi);
        y.insert(yi);
    }

    long long xMax = -1e9;
    long long xMin = 1e9;
    for(long long i : x){
        xMax = std::max(xMax, i);
        xMin = std::min(xMin, i);
    }

    long long yMax = -1e9;
    long long yMin = 1e9;
    for(long long i : y){
        yMax = std::max(yMax, i);
        yMin = std::min(yMin, i);
    }

    std::cout<<(xMax-xMin)*(yMax-yMin);


}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;

    while(t--){
        solve();
        std::cout<<'\n';
    }

    return 0;
}