#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    long long negativeCount = 0;
    std::cin>>n;

    std::vector<long long>c;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        if(curr < 0){
            negativeCount++;
        }
        c.push_back(negativeCount);
    }

    long long pos = 0;
    long long neg = 0;
    long long even = 0;
    long long odd = 0;

    for(long long i = 0; i<n; i++){
        if(c[i] % 2 == 0){
            pos += 1 + even;
            neg += odd;

            even++;
        } else {
            neg += 1 + even;
            pos += odd;

            odd++;
        }
    }

    std::cout<<neg << ' ' <<  pos;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t = 1;

    while(t--){
        solve();
    }

    return 0;
}