#include <bits/stdc++.h>

void solve(){
    long long n;
    long long m;
    std::string a;
    std::string b;

    std::cin>>n;
    std::cin>>m;
    std::cin.ignore();

    std::getline(std::cin, a);
    std::getline(std::cin, b);

    long long k = 0;
    long long i = 0;
    while(i < m && k < n){
        if(b[i] == a[k]){
            k++;
        }

        i++;
    }

    std::cout<<k<<'\n';
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