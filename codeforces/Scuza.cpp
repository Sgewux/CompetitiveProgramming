#include<iostream>
#include<vector>
#include<utility>
#include<cmath>

long long solve(long long query, std::vector<std::pair<long long, long long>>& steps, long long s, long long e){
    long long m;
    while(s < e){
        m = (s+e)/2;
        if(steps[m].first == query){
            return steps[m].second;
        }else if(query < steps[m].first){
            e = m-1;
        } else if(query > steps[m].first){
            s = m+1;
        }
    }

    m = (s+e)/2;
    if(steps[m].first <= query){
        return steps[m].second;
    } else {
        if(m>0){
            return steps[m-1].second;
        }else {
            return 0;
        }
    }

}

int main(){

    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;
    long long n;
    long long q;
    

    for(long long j = 0; j<t; j++){
        std::cin>>n;
        std::cin>>q;
        long long current;
        long long lastSeen = -1;
        long long acc = 0;
        std::vector<std::pair<long long, long long>> steps; //leg length, max top

        for(long long i = 0; i < n; i++){
            std::cin>>current;
            acc+=current;

            if(current > lastSeen){
                std::pair<long long, long long> p(current, acc);
                steps.push_back(p);
                lastSeen = current;
            } else if(current == lastSeen || current < lastSeen){
                steps.back().second = acc;
            }
        }
        
        // for(auto e : steps){
        //     std::cout<<e.first << " : " << e.second <<std::endl;
        // }
        
        long long query;
        for(long long i = 0; i < q; i++){
            std::cin>>query;
            std::cout<<solve(query, steps, 0, steps.size()-1)<<" ";
        }

        std::cout<<'\n';
    }

    return 0;
}