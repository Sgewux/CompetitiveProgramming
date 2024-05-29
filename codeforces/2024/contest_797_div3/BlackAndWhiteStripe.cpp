#include <bits/stdc++.h>

void solve(){
    long long n;
    long long k;
    std::string s;
    std::cin>>n;
    std::cin>>k;

    std::cin.ignore();
    std::getline(std::cin, s);
    long long wCnt = 0;

    for(long long i = 0; i<k; i++){
        if(s[i] == 'W'){
            wCnt++;
        }
    }

    long long ans = wCnt;
    long long i = 1;

    while(k<n){
        if(s[i-1] == 'W'){
            wCnt--;
        }

        if(s[k] == 'W'){
            wCnt++;
        }

        ans = std::min(ans, wCnt);
        i++;
        k++;
    }

    std::cout<<ans<<'\n';
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