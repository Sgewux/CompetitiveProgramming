#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    std::vector<long long>v;
    std::unordered_map<long long, std::vector<long long>>m;
    std::cin>>n;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        if(!(curr%2 == 0)){
            curr += (curr%10);
        }
        v.push_back(curr);
    }

    std::sort(v.begin(), v.end());

    for(long long i = 0; i<n-1; i++){
        if(v[i+1] - v[i] > 0){
            long long diff = v[i+1] - v[i];
            
            if(v[i]%10 == 0){
                std::cout<<"NO"<<'\n';
                return;
            }

            if(!m.count(v[i]%10)){
                std::vector<long long>currVec = {0};
                std::unordered_set<long long> seen;

                long long digit = v[i]%10;
                while(!seen.count(digit)){
                    currVec.push_back(currVec.back() + digit);
                    seen.insert(digit);
                    digit *= 2;
                    digit %= 10;
                }

                m[v[i]%10] = currVec;
            }

            diff %= m[v[i]%10].back();
            bool found = false;

            for(auto& n : m[v[i]%10]){
                if(n==diff){
                    found = true;
                }
            }

            if(!found){
                std::cout<<"NO"<<'\n';
                return;
            }
        }
    }

    std::cout<<"YES"<<'\n';
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