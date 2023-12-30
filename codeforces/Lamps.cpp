#include <bits/stdc++.h>

struct sort_pred{
    bool operator()(const std::pair<long long, long long>& left, const std::pair<long long, long long>& right){
        if(left.first == right.first){
            return left.second > right.second;
        } else {
            return left.first < right.first;
        }
    }
};

long long solve(std::vector<std::pair<long long, long long>>& l){
    long long ans = 0;
    long long currSmallest = 0;
    long long currOn = 0;
    std::unordered_map<long long, long long> history;
    std::sort(l.begin(), l.end(), sort_pred());

    for(std::pair p : l){

        if(history.count(currOn)){
            long long newOn = currOn - history[currOn];
            history.erase(currOn);
            currSmallest = currOn;
            currOn = newOn;
        }

        if((p.first > currOn) && (p.first > currSmallest)){
            ans+=p.second;
            currOn++;

            if(history.count(p.first)){
                history[p.first]++;
            } else {
                history[p.first] = 1;
            }
        }
    }

    return ans;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    std::vector<std::pair<long long, long long>> l;
    long long a;
    long long b;
    std::cin>>t;

    while(t--){
        l.clear();
        std::cin>>n;
        for(long long i = 0; i<n; i++) { 
            std::cin>>a;
            std::cin>>b;
            l.push_back({a,b});
        }

        std::cout<<solve(l)<<'\n';
    }

    return 0;
}