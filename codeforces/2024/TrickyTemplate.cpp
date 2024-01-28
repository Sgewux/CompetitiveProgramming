#include <bits/stdc++.h>

void solve(long long n, std::string_view a, std::string_view b, std::string_view c){
    for(long long i = 0; i<n; i++){
        if( (c[i] != a[i]) && (c[i] != b[i])){
            std::cout<<"YES"<<'\n';
            return;
        }
    }

    std::cout<<"NO"<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    std::string a;
    std::string b;
    std::string c;

    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::cin.ignore();

        std::getline(std::cin, a);
        std::getline(std::cin, b);
        std::getline(std::cin, c);

        solve(n,a,b,c);
    }

    return 0;
}