#include <bits/stdc++.h>

void solve(){
    long long n;
    std::string s;
    std::cin>>n;
    std::cin.ignore();
    std::getline(std::cin, s);

    std::vector<std::pair<char, char>> instructions;
    std::map<char, int> m;
    std::map<char, int> mR;
    std::map<char, int> mH;

    for(long long i = 0; i<n; i++){
        m[s[i]]++;
        instructions.push_back({s[i], '0'});
    }

    for(auto& k : m){
        if(k.second % 2 == 0){
            mR[k.first] = k.second/2;
            mH[k.first] = k.second/2;
        } else {
            if(k.first == 'N' && (m['S'] % 2 == 1)){
                mR[k.first] = std::floor(k.second/2) + 1;
                mH[k.first] = std::floor(k.second/2);
            } else if(k.first == 'S' && (m['N'] % 2 == 1)){
                mR[k.first] = std::floor(k.second/2) + 1;
                mH[k.first] = std::floor(k.second/2);
            } else if(k.first == 'E' && (m['W'] % 2 == 1)){
                mR[k.first] = std::floor(k.second/2);
                mH[k.first] = std::floor(k.second/2) + 1;
            } else if(k.first == 'W' && (m['E'] % 2 == 1)){
                mR[k.first] = std::floor(k.second/2);
                mH[k.first] = std::floor(k.second/2) + 1;
            } else {
                std::cout<< "NO" <<'\n';
                return;
            }
        }
    }


    std::pair<long long, long long> rCords = {0,0};
    std::pair<long long, long long> hCords = {0,0};
    long long rMoves = 0;
    long long hMoves = 0;

    for(long long i = 0; i<n; i++){
        if(mR[instructions[i].first] > 0){
            instructions[i].second = 'R';
            mR[instructions[i].first]--;

            if(instructions[i].first == 'N'){
                rCords.second++;
            } else if (instructions[i].first == 'S'){
                rCords.second--;
            } else if(instructions[i].first == 'E'){
                rCords.first++;
            } else {
                rCords.first--;
            }

            rMoves++;

        } else if(mH[instructions[i].first] > 0){
            instructions[i].second = 'H';
            mH[instructions[i].first]--;

            if(instructions[i].first == 'N'){
                hCords.second++;
            } else if (instructions[i].first == 'S'){
                hCords.second--;
            } else if(instructions[i].first == 'E'){
                hCords.first++;
            } else {
                hCords.first--;
            }

            hMoves++;
        }
    }

    if(rCords.first == hCords.first && rCords.second == hCords.second && hMoves > 0 && rMoves > 0){
        for(long long i = 0; i<n; i++){
            std::cout<<instructions[i].second;
        }

        std::cout<< '\n';
        return;

    } else {
        std::cout<< "NO" <<'\n';
        return;
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