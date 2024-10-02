#include <bits/stdc++.h>

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return (res * res * a);
    else
        return (res * res);
}

void solve(){
    long long n;
    std::cin>>n;

    long long powCnt = 0;
    std::vector<long long> pows;
    for(long long i = 60; i>=0; i--){
        long long pow = binpow(2,i);
        if(n >= pow){
            long long a = n-pow;
            powCnt++;
            pows.push_back(pow);
            n-=pow;
        }
    }

    if(powCnt == 1){
        std::cout<<1<<'\n';
        std::cout<<pows[0]<<'\n';
        return;
    }

    std::cout<<powCnt+1<<'\n';
    long long e = 0;

    while(e <= powCnt){
        long long ans = 0;
        for(long long i = 0; i<powCnt; i++){
            if(i != e){
                ans+=pows[i];
            }
        }

        std::cout<<ans<<" ";
        e++;
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