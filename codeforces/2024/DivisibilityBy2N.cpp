#include <bits/stdc++.h>
 
void solve(){
    long long n;
    long long curr;
    long long countOfPowers = 0;
    std::cin>>n;
 
    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        while (curr%2 == 0){
            countOfPowers++;
            curr /= 2;
        }
    }

    if(countOfPowers >= n){
        std::cout<<0;
        return;
    }
 
    long long remainder = n-countOfPowers;
    long long ans = 0;
    long long last = 0;
 
    for(long long i = 17; i>=1; i--){
 
        long long power = std::pow(2,i);
        long long available = std::floor(n/power) - last;
        long long required = (remainder % i ) == 0 ? remainder/i : std::floor(remainder/i) + 1;
 
        remainder = available >= required ? 0 : remainder - (available * i);
        ans = available >= required ? ans + required : ans + available;
        last = std::floor(n/power);
 
    }
 
 
    if(remainder == 0){
        std::cout<<ans;
    } else {
        std::cout<<-1;
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
        std::cout<<'\n';
    }
 
    return 0;
}