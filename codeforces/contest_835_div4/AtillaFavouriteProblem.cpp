#include <bits/stdc++.h>

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    
    long long t;
    long long n;
    char c;
    std::cin>>t;

    while(t--){
        std::vector<int>letters;
        std::cin>>n;
        for(long long i = 0; i< n; i++){
            std::cin>>c;
            letters.push_back((int)c);
            std::sort(letters.begin(), letters.end());
            
        }

        std::cout<<letters[n-1] - 96<<'\n';


    }

    return 0;
}