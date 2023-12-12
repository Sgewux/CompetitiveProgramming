#include <bits/stdc++.h>

long long solve(long long n, long long k, long long d, long long w, std::vector<long long>& t){
    long long c = 1;
    long long currk = k;
    long long l = 0;

    for(long long i = 0; i<n; i++){
        if( ( (t[i] - t[l] - d) <= w ) && currk>0){
            currk--;
        } else {
            l = i;
            c++;
            currk = k-1;
        }
    }

    return c;
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long tn;
    std::cin>>tn;
    long long n;
    long long k;
    long long d;
    long long w;
    long long curr;
    std::vector<long long> t;

    while(tn--){
        t.clear();
        std::cin>>n;
        std::cin>>k;
        std::cin>>d;
        std::cin>>w;

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            t.push_back(curr);
        }

        std::cout<<solve(n,k,d,w,t)<<'\n';
    }

    return 0;
}