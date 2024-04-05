#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin>>n;

    long long l = 2;
    long long r = 1e10;
    
    long long m;
    long long cantOfIceCreams;
    while(l<r){
        m = (l+r)/2;
        cantOfIceCreams = ((m-1)*m)/2;

        if(cantOfIceCreams == n){
            std::cout<<m<<'\n';
            return;
        } else if(cantOfIceCreams<n){
            l = m+1;
        } else if(cantOfIceCreams>n){
            r = m-1;
        }
    }

    m = (l+r)/2;
    cantOfIceCreams = ((m-1)*m)/2;

    if(cantOfIceCreams <= n){
        std::cout<<m + (n-cantOfIceCreams)<<'\n';
    } else {
        m--;
        cantOfIceCreams = ((m-1)*m)/2;
        std::cout<<m + (n-cantOfIceCreams)<<'\n';
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