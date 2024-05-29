#include <bits/stdc++.h>

void solve(){
    long long numOfCuts;
    std::string s;
    std::vector<long long> cuts;
    std::getline(std::cin, s);
    char lastSeen = s[0];
    bool ordered = true;

    for(long long i = 0; i<s.length(); i++){
        ordered = ordered && (lastSeen <= s[i]);
        if(s[i] != lastSeen){
            cuts.push_back(i);
        }

        lastSeen = s[i];
    }

    numOfCuts = cuts.size();

    if(ordered){
        numOfCuts = 0;
    } else if(s.length() >= 2){
       if(numOfCuts >= 2){
            numOfCuts--;
       }
    }

    std::cout<<numOfCuts+1<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;
    std::cin.ignore();

    while(t--){
        solve();
    }

    return 0;
}