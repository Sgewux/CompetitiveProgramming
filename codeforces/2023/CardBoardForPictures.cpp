#include <bits/stdc++.h>

long long borderArea(long long n, long long w, long long c, std::vector<long long>& s){
    long long border = 0;
    for(long long i = 0; i<n; i++){
        if(border > c || border < 0){
            return c+1;
        }
        border += (2*w)*(2*s[i] + 2*w);
    }

    return border;
}

long long solve(long long n, long long c, long long a, std::vector<long long>& s){
    c-=a;
    long long l = 1;
    long long r = 1e9;
    long long w;

    while(l<=r){
        w = (l+r)/2;
        long long border = borderArea(n,w,c,s);

        if(border == c){
            return w;
        } else if(border < c){
            l = w+1;
        } else if(border > c){
            r = w-1;
        }
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long c;
    long long curr;

    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::cin>>c;
        std::vector<long long>s;
        long long a = 0;

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            a += std::pow(curr, 2);
            s.push_back(curr);
        }

        std::cout<<solve(n,c,a,s)<<'\n';
    }

    return 0;
}