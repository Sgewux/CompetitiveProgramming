#include <bits/stdc++.h>

bool solve(long long n, std::vector<long long>& a){
    std::unordered_map<long long,long long>p;
    for(long long num : a){
        while(num%2 == 0){
             if(!p.count(2)){
                p[2] =0;
             }

             p[2]++;

             num/=2;
        }

        for(long long i = 3; i<=std::sqrt(num); i+=2){
            while(num%i == 0){
                if(!p.count(i)){
                    p[i]=0;
                }

                p[i]++;

                num/=i;
            }
        }

        if(num>2){
            if(!p.count(num)){
                p[num] = 1;
            } else {
                p[num]++;
            }
        }
    }

    for(auto& k : p){
        if(k.second % n != 0){
            return false;
        }
    }

    return true;
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
        std::cin>>n;
        std::vector<long long>a;
        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            a.push_back(curr);
        }

        solve(n,a) ? std::cout<<"YES" : std::cout<<"NO";
        std::cout<<'\n';
    }

    return 0;
}