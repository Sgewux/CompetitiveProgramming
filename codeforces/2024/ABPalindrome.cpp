#include <bits/stdc++.h>

void solve(long long a, long long b, std::string_view str){
    std::vector<char> cStr;
    std::vector<std::pair<long long, long long>>pairs;
    std::unordered_map<char, long long> m;
    m['0'] = a;
    m['1'] = b;

    for(auto c : str){
        cStr.push_back(c);
    }
    
    if((a+b)%2 != 0){
        long long middle = std::floor((a+b)/2);
        if(cStr[middle] == '?'){
            if(m['0']%2 != 0){
                cStr[middle] = '0';
                m['0']--;
            } else {
                cStr[middle] = '1';
                m['1']--;
            }
        } else {
            if(m[cStr[middle]] >= 1){
                m[cStr[middle]]--;
            } else {
                std::cout<<-1;
                return;
            }
        }
    }

    for(long long i = 0; i<(long long)std::floor((a+b)/2); i++){

        if(cStr[i]!='?'){
            if(cStr[(a+b)-i-1] == cStr[i] || cStr[(a+b)-i-1] == '?'){
                if(m[cStr[i]] >= 2){
                    cStr[(a+b)-i-1] = cStr[i];
                    m[cStr[i]] -= 2;
                } else {
                    std::cout<<-1;
                    return;
                }
               
            } else {
                std::cout<<-1;
                return;
            }
        } else {
            if(cStr[(a+b)-i-1] == '?'){
                pairs.push_back({i, (a+b)-i-1});
            } else {
                if(m[cStr[(a+b)-i-1]] >= 2){
                    cStr[i] = cStr[(a+b)-i-1];
                    m[cStr[(a+b)-i-1]]-=2;
                } else {
                    std::cout<<-1;
                    return;
                }
            }
        }
    }

    if(pairs.size() > 0){
        if(m['0']%2 == 0 && m['1']%2 == 0){
            for(std::pair p : pairs){
                if(m['0']>=2){
                    cStr[p.first] = '0';
                    cStr[p.second] = '0';
                    m['0']-=2;
                } else {
                    cStr[p.first] = '1';
                    cStr[p.second] = '1';
                    m['1']-=2;
                }
            }
        } else {
            std::cout<<-1;
            return;
        }
    }

    for(char c : cStr){
        std::cout<<c;
    }

    
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long a;
    long long b;
    std::string str;
    std::cin>>t;

    while(t--){
        std::cin>>a;
        std::cin>>b;
        std::cin.ignore();
        std::getline(std::cin, str);

        solve(a, b, str);
        std::cout<<'\n';
    }

    return 0;
}