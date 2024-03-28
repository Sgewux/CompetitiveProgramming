#include <bits/stdc++.h>

bool possible(long long k, std::string& s){
    std::map<std::string, long long> m;
    long long i = 0;
    while (i < s.length()){
        std::string sub = s.substr(i, k);
        if(!m.count(sub)){
            m[sub] = 1;
        } else {
            m[sub]++;
        }

        i+=k;
    }

    if(m.size() == 2){
        long long c = 0;
        for(auto& p : m){
            if(p.second == 1){
                c++;
            }
        }

        if(c == 0){
            return false;
        } else {
            std::vector<std::string> v;
            for(auto& p : m){
                v.push_back(p.first);
            }

            long long diff = 0;
            for(long long i = 0; i<k; i++){
                if(v[0][i] != v[1][i]){
                    diff++;
                }
            }

            if(diff <= 1){
                return true;
            } else {
                return false;
            }
        }
    } else if(m.size() == 1) {
        return true;
    } else {
        return false;
    }
    
}

void solve(long long n, std::string& s){
    long long ans = n;
    for(long long i = 1; i<=std::sqrt(n); i++){
        if(n%i == 0){
            if(possible(i, s)){
                ans = std::min(ans, i);
            }

            if(possible(n/i, s)){
                ans = std::min(ans, n/i);
            }
        }
    }

    std::cout<<ans<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    std::string s;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::cin.ignore();
        std::getline(std::cin,s);

        solve(n, s);
    }

    return 0;
}