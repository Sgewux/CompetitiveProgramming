#include <bits/stdc++.h>

void solve(long long n, std::vector<long long>& a, long long min, long long minIdx){
    std::vector<std::pair<long long, long long>>ansV;
    long long ansCnt = 0;

    if(min == 1){
        for(long long i = 0; i<n; i++){
            if(a[i]!=1){
                std::cout<<-1<<'\n';
                return;
            }
        }

        std::cout<<0<<'\n';
        return;
    } else {
        long long moves;
        long long newMin = min;
        long long newMinIdx = minIdx;
        do{
            moves = 0;
            for(long long i = 0; i<n; i++){

                while(a[i] > min){
                    long long cealing = a[i]%min == 0 ? a[i]/min : std::floor(a[i]/min)+1;
                    a[i] = cealing;
                    ansCnt++;
                    moves++;
                    ansV.push_back({i+1, minIdx+1});
                }
                
                if(a[i] < newMin){
                    newMin = a[i];
                    newMinIdx = i;
                }
            }

            min = newMin;
            minIdx = newMinIdx;
        
        } while (moves > 0);

        std::cout<<ansCnt<<'\n';
        for(auto p : ansV){
            std::cout<<p.first<<" "<<p.second<<'\n';
        }
        
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long curr;
    std::cin>>t;

    while(t--){
        long long min = 2e9 + 1;
        long long minIdx;
        std::vector<long long> a;
        std::cin>>n;
        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            a.push_back(curr);

            if(curr < min){
                min = curr;
                minIdx = i;
            }
        }
        
        solve(n, a, min, minIdx);
    }

    return 0;
}