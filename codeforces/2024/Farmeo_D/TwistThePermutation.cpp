#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    std::cin>>n;
    std::vector<long long>p;
    std::unordered_map<long long, long long>inputPositions;
    std::unordered_map<long long, long long>currPositions;
    currPositions[1] = 0;
    currPositions[2] = 1;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        inputPositions[curr] = i;
        p.push_back(curr);
    }

    std::cout<< 0 <<" ";

    for(long long i = 1; i<n-1; i++){
        long long leftElement = -1;
        long long j = inputPositions[i+2];
        while(leftElement == -1){
                if(j == 0){
                    j = n-1;
                } else {
                    j--;
                }

                if(currPositions.count(p[j])){
                    leftElement = p[j];
                }
        }

        long long swaps = (currPositions.size() - 1) - currPositions[leftElement];
        std::cout<< swaps << ' ';

        for(auto& kv : currPositions){
            kv.second = (kv.second + swaps) % currPositions.size();
        }

        currPositions[i+2] = i+1;

    }

    if(inputPositions[n] == currPositions[n]){
        std::cout<< 0 <<' ';
    } else {
        std::cout<<inputPositions[n] + 1 << ' ';
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