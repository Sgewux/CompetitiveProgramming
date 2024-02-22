#include <bits/stdc++.h>

long long solve(long long n, std::deque<long long>& d){

    if(d.front() == d.back()){
        long long t = d.front();
        while(!d.empty() && (d.front() == t)){
            d.pop_front();
        }

        while(!d.empty() && (d.back() == t)){
            d.pop_back();
        }

        return d.size();

    } else {
        long long eqStart = 1;
        for(long long i = 1; i<n; i++){
            if(d[i] == d[0]){
                eqStart++;
            } else {
                break;
            }
        }

        long long eqEnd = 1;
        for(long long i = n-2; i>=0; i--){
            if(d[i] == d[n-1]){
                eqEnd++;
            } else{
                break;
            }
        }

        return n-std::max(eqStart, eqEnd);
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
        std::cin>>n;
        std::deque<long long> d;

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            d.push_back(curr);
        }

        std::cout<<solve(n,d)<<'\n';
    }

    return 0;
}