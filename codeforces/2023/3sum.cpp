#include <bits/stdc++.h>

bool solve(std::unordered_map<int, long long>& b){
    for(int i = 0; i<=9; i++){
        for(int j = 0; j<=9; j++){
            for(int k = 0; k<=9; k++){
                if((i + j + k) == 3 || (i + j + k) == 13 || (i + j + k) == 23){
                    std::vector<int> candidate = {i,j,k};
                    int icount = std::count(candidate.begin(), candidate.end(),i);
                    int jcount = std::count(candidate.begin(), candidate.end(),j);
                    int kcount = std::count(candidate.begin(), candidate.end(),k);
                    if(b.count(i) && b.count(j) && b.count(k)){
                        if(b[i] >= icount && b[j]>=jcount && b[k]>=kcount){
                            return true;
                        }
                    }
                }
                
            }
        }
    }

    return false;
}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long cur;
    std::cin>>t;
    while(t--){
        std::cin>>n;
        std::unordered_map<int, long long> b;
        for(long long i = 0; i< n; i++){
            std::cin>>cur;
            cur = cur%10;
            if(b.count(cur)){
                b[cur]++;
            } else {
                b[cur] = 1;
            }
        }

        std::cout<< (solve(b) == true ? "YES" : "NO") <<'\n';

    }

    return 0;
}