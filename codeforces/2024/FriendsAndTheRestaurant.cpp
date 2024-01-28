#include <bits/stdc++.h>

long long solve(long long n, std::vector<long long>& x, std::vector<long long>& y){
    std::deque<long long>a;
    std::vector<long long>b;
    long long cantB = 0;

    for(long long i = 0; i<n; i++){
        if(y[i]-x[i] < 0){
            a.push_back(std::abs(y[i]-x[i]));
        } else {
            b.push_back(y[i]-x[i]);
            cantB++;
        }
    }

    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    long long ans = 0;
    long long currCantB = cantB;
    for(long long i = 0; i<cantB; i++){
        if(a.empty()){
            break;
        } else {
            if(b[i] >= a.front()){
                a.pop_front();
                currCantB--;
                ans++;
            }
        }
    }

    ans += std::floor(currCantB/2);
    return ans;
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
        std::vector<long long>x;
        std::vector<long long>y;

        for(long long i = 0; i<n; i++){
           std::cin>>curr;
           x.push_back(curr);
        }

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            y.push_back(curr);
        }

        std::cout<<solve(n,x,y)<<'\n';
    }

    return 0;
}