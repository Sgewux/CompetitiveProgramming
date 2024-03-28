#include <bits/stdc++.h>

long long solve(long long n, std::string_view s, std::string_view f){
    long long toAdd = 0;
    long long toMove = 0;
    long long ans = 0;

    for(long long i = 0; i<n; i++){
        if(s[i] == '0' && f[i] == '1'){
            toAdd++;
        } else if(s[i] == '1' && f[i] == '0'){
            toMove++;
        }
    }

    if(toAdd >= toMove){
        return toMove + (toAdd-toMove);
    } else {
        return toAdd + (toMove - toAdd);
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    std::string s;
    std::string f;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::cin.ignore();
        std::getline(std::cin, s);
        std::getline(std::cin, f);

        std::cout<<solve(n,s,f)<<'\n';
    }

    return 0;
}