#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin>>n;

    if(n == 1){
        std::cout<<"##"<<'\n';
        std::cout<<"##"<<'\n';
    } else {
        int state = 0;
        for(long long i = 0; i<n; i++){
            if(i%2 != 0){
                state = 1;
            } else {
                state = 0;
            }

            for(long long j = 0; j<n; j++){
                if((j+state) % 2 == 0){
                    std::cout<<"##";
                } else {
                    std::cout<<"..";
                }
            }

            std::cout<<'\n';

            for(long long j = 0; j<n; j++){
                if((j+state) % 2 == 0){
                    std::cout<<"##";
                } else {
                    std::cout<<"..";
                }
            }

            std::cout<<'\n';
        }
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