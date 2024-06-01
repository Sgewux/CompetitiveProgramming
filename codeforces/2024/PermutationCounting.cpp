#include <bits/stdc++.h>

void solve(){
    long long n;
    long long k;
    std::cin>>n;
    std::cin>>k;
    std::vector<long long>v(n);

    for(long long i = 0; i<n; i++){
        std::cin>>v[i];
    }

    std::sort(v.begin(), v.end());

    long long min = v[0];
    long long lastSeen = v[0];
    long long i =0;

    while(k > 0 && i < n){
        if(v[i] != lastSeen){

            long long diff = v[i] - min;

            if(k >= diff*i){
                k-= diff*i;
                min = v[i];
            } else {
                min = min + std::floor(k/i);
                k %= i;
                break;
            }

            lastSeen = v[i];
        }

        i++;
    }

    long long leftOvers = k;

    for(long long i = 0; i<n; i++){
        if(v[i] > min){
            leftOvers++;
        }
    }

    std::cout<< n*(min-1) + 1 + leftOvers <<'\n';
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