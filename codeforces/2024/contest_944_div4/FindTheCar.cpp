#include <bits/stdc++.h>

std::pair<long long, long long> bSearch(long long t, std::vector<long long>& a){
    long long l = 0;
    long long r = a.size() - 1;
    long long m;

    while(l < r){
        m = (l+r)/2;

        if(a[m] == t){
            return {m,m};
        } else if(a[m] < t){
            l = m+1;
        } else if(a[m] > t){
            r = m-1;
        }
    }

    m = (l+r)/2;

    if(a[m] == t){
        return {m,m};
    } else if(a[m] > t){
        return {m-1,m};
    } else {
        return {m, m+1};
    }
}

void solve(){
    long long n;
    long long k;
    long long q;
    std::cin>>n;
    std::cin>>k;
    std::cin>>q;
    std::vector<long long>a(k+1,0);
    std::vector<long long>b(k+1, 0);

    for(long long i = 0; i<k; i++){
        std::cin>>a[i+1]; 
    }

    for(long long i = 0; i<k; i++){
        std::cin>>b[i+1];
    }

    long long curr;

    for(long long i = 0; i<q; i++){
        std::cin>>curr;
        std::pair<long long, long long> bounds = bSearch(curr,a);

        if(bounds.first == bounds.second){

            std::cout<<b[bounds.first]<< ' ';
            
        } else {
            long long u = (double) (b[bounds.second] - b[bounds.first]) * (curr - a[bounds.first]) ;
            long long ans =b[bounds.first] +  ( u / (a[bounds.second] - a[bounds.first]));

            std::cout<<  b[bounds.first] + (((long long) (curr - a[bounds.first]) * (b[bounds.second] - b[bounds.first])) / (a[bounds.second] - a[bounds.first])) <<' ';
        }

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