#include <bits/stdc++.h>

std::string solve(std::vector<long long>& x){
    long long n = x.size();

    if(n == 1){
        return "YES";
    } else if(n==2){
        return "YES";
    }

    bool left = x[0]<x[1] ? true : false;
    bool right = x[n-2]>x[n-1] ? true : false;
    bool middle = false;

    for(long long i = 0; i<=n-3; i++){
        if((x[i] > x[i+1]) && (x[i+1] < x[i+2])){
            if(middle){
                return "NO";
            } else {
                middle = true;
            }
        }
    }

    if((!left && !right) && middle){
        return "YES";
    } else if((!left && !middle) && right){
        return "YES";
    } else if((!right && !middle) && left){
        return "YES";
    } else {
        return "NO";
    }
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;

    long long lastSeen;
    long long curr;
    long long n;
    std::vector<long long> x;

    while(t--){
        x.clear();
        lastSeen =-1;
        std::cin>>n;
        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            if(curr!=lastSeen){
                x.push_back(curr);
            }

            lastSeen = curr;
        }

        std::cout<<solve(x)<<'\n';
    }

    return 0;
}