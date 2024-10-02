#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin>>n;
    long long k = (n >= 10 ? (n==100 ? 3 : 2) : 1);
    std::vector<std::pair<long long, long long>> ans;

    long long d = n;
    long long cantDigits = k;
    long long a;
    long long b;
    
    if(n == 1){
        a = 2;
        b = 1;

        while(a<=1e4 && b<=1e4){
            if(a<=1e4 && b<=std::min(n*a, (long long)1e4) && a>0 && b>0) ans.push_back({a,b}); 
            a++;
            b++;
        }
        
        std::cout<<ans.size()<<'\n';
        for(auto& p : ans){
            std::cout<<p.first << " " <<p.second <<'\n';
        }

        return;
    }

    if((d-cantDigits) % (n-k) == 0){
        a = (d-cantDigits)/(n-k);
        b = k*a - cantDigits;
        if(a<=1e4 && b<=std::min(n*a, (long long)1e4) && a>0 && b>0) ans.push_back({a,b}); 
    }

    while(d < 1e10){
        for(long long i = k-1; i>=0; i--){
            cantDigits++;
            d *= 10;
            d += (n/(i > 0 ? 10*i : 1)) % 10;
            
            if((d-cantDigits) % (n-k) == 0){
                a = (d-cantDigits)/(n-k);
                b = k*a - cantDigits;
                if(a<=1e4 && b<=std::min(n*a, (long long)1e4) && a>0 && b>0) ans.push_back({a,b}); 
            }
        }

    }

    std::cout<<ans.size()<<'\n';
    for(auto& p : ans){
        std::cout<<p.first << " " <<p.second <<'\n';
    }

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