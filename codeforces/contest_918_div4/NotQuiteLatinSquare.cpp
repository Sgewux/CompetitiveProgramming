#include <bits/stdc++.h>

void solve(std::vector<std::string>& square){
    long long ix;
    long long jx;
    for(long i = 0; i<3; i++){
        for(long long j = 0; j<3; j++){
            if(square[i][j] == '?'){
                ix = i;
                jx = j;
                break;
            }
        }
    }

    std::unordered_set<char> found;

    for(long long i = 0; i<3; i++){
        found.insert(square[i][jx]);
    }

    for(long long j = 0; j<3; j++){
        found.insert(square[ix][j]);
    }

    if(!found.count('A')){
        std::cout<<'A';
    } else if(!found.count('B')){
        std::cout<<'B';
    } else {
        std::cout<<'C';
    }

    std::cout<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::vector<std::string> square;
    std::string curr;
    std::cin>>t;
    std::cin.ignore();
    while(t--){
        square.clear();

        for(long long i = 0; i < 3; i++){
           std::getline(std::cin, curr);
           square.push_back(curr);
        }

        solve(square);
    }

    return 0;
}