#include <bits/stdc++.h>

void solve(long long n, std::string& str){
    std::vector<long long>p(n+1, 0);
    double ansDis = 1e9;
    long long ansIdx;

    for(long long i = 1; i<=n; i++){
        p[i] = str[i-1] == '1' ? p[i-1] + 1 : p[i-1];
    }

    for(long long i = 0; i<=n; i++){
        long long peopleLeft = i;
        long long peopleRight = n-i;
        long long l = peopleLeft%2 == 0 ? peopleLeft/2 : std::floor(peopleLeft/2) + 1;
        long long r = peopleRight%2 == 0 ? peopleRight/2 : std::floor(peopleRight/2) + 1;
        if((peopleLeft - p[i]) >= l && (p[n]-p[i]) >= r){
            double dis = std::abs(((double)n/2) - i);
            if(dis < ansDis){
                ansDis = std::abs((n/2) - i);
                ansIdx = i;
            }
        }
    }


    std::cout<<ansIdx<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    std::string str;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::cin.ignore();
        std::getline(std::cin, str);

        solve(n, str);
    }

    return 0;
}