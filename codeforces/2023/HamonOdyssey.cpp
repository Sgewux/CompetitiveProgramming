#include <bits/stdc++.h>

void solve(){
    long long n;
    long long bitwiseAcc;
    long long curr;
    std::vector<long long>a;
    std::cin>>n;
    std::cin>>bitwiseAcc;
    a.push_back(bitwiseAcc);

    for(long long i = 1; i < n; i++){
        std::cin>>curr;
        bitwiseAcc =  bitwiseAcc & curr;
        a.push_back(curr);
    }

    if(bitwiseAcc != 0){
        std::cout<<1<<'\n';
    } else {
        long long c = 0;
        curr = a[0];

        for(long long i = 0 ; i < n; i++){
            if( (curr & a[i]) == 0){
                c++;
                curr = (i + 1) < n ? a[i+1] : 1; // reached last num
            } else {
                curr = curr & a[i];
            }
        }

        std::cout<<c<<'\n';

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