#include <bits/stdc++.h>

void solve(){
    long long n;
    long long mex = 0;
    long long choice = 1e9;
    long long curr;
    std::cin>>n;
    std::vector<long long> v;
    std::map<long long, long long>freq;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        if(!freq.count(curr)) v.push_back(curr);
        freq[curr]++;
    }

    std::sort(v.begin(), v.end());

    for(auto& e : v){
        if(e == mex) mex++;
    }

    for(long long i = 0; i<v.size(); i++){
        if(freq[v[i]] == 1){
            freq[v[i]]--;
            break;
        }
    }
    
    for(long long i = 1; i<v.size(); i++){
        if(v[i] > mex) break;

        if(freq[v[i]]==1){
            choice = v[i];
            break;
        }
    
    }

    std::cout<<std::min(choice, mex)<<'\n';
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