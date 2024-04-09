#include <bits/stdc++.h>

void solve(){
    long long ans = 0;
    long long n;
    long long k;
    long long curr;
    std::cin>>n;
    std::cin>>k;

    std::deque<long long>a;
    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        a.push_back(curr);
    }

    long long l = k%2 == 0? k/2 : std::floor(k/2) + 1;
    long long r = k%2 == 0? k/2 : std::floor(k/2);
    long long i = 0;
    while(!(r==0&&l==0) && !a.empty()){
        if(i%2 == 0){
            if(l >= a.front()){
                ans++;
                l-=a.front();
                a.pop_front();
            } else {
                a.front() -= l;
                l=0;
            }
        } else {
            if(r >= a.back()){
                ans++;
                r-=a.back();
                a.pop_back();
            } else {
                a.back() -= r;
                r=0;
            }
        }
        i++;
    }


    std::cout<<ans<<'\n';
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