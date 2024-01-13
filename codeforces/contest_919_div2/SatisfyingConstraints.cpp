#include <bits/stdc++.h>

void solve(){
    long long n;
    long long currKind;
    long long currX;
    long long lowerBound = -1;
    long long upperBound =  2e9 + 1;

    long long ans = 0;
    std::set<long long> s;
    std::cin>>n;

    for(long long i = 0; i<n; i++){
        std::cin>>currKind;
        std::cin>>currX;

        if(currKind == 1){
            lowerBound = std::max(lowerBound, currX);
        } else if(currKind == 2){
            upperBound = std::min(upperBound, currX);
        } else {
            s.insert(currX);
        }
    }

    long long outsidersCnt = 0;
    for(long long i : s){
        if(i>=lowerBound && i<=upperBound){
            outsidersCnt++;
        }
    }

    ans = ((upperBound-lowerBound) + 1) - outsidersCnt ;
    ans = ans >= 0? ans : 0;

    std::cout<<ans;
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