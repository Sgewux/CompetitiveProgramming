#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin>>n;
    std::vector<long long> s(n);

    for(long long i = 0; i<n; i++){
        std::cin>>s[i];
    }
    long long bi;
    std::string m; 
    for(long long i = 0; i<n; i++){
        std::cin>>bi;
        std::cin.ignore();
        std::getline(std::cin, m);
        std::reverse(m.begin(), m.end());

        for(long long j = 0; j<bi; j++){
            if(m[j] == 'D'){
                s[i]++;
                if(s[i] == 10){
                    s[i] = 0;
                }
            } else {
                s[i]--;
                if(s[i] == -1){
                    s[i] = 9;
                }
            }
        }
    }

    for(long long i = 0; i<n; i++){
        std::cout<<s[i]<<' ';
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