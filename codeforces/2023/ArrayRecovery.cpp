#include <bits/stdc++.h>

void solve(long long n, std::vector<long long>& b){
    std::vector<long long> ans;
    ans.push_back(b[0]);

    for(long long i = 1; i<n; i++){
        long long ai1 = b[i] + ans[i-1];
        long long ai2 = ans[i-1] - b[i];

        if( ( (ai1 >= 0) && (ai2 >= 0) ) && (ai1 != ai2)){
            ans.clear();
            ans = {-1};
            break;
        } else {
            ans.push_back(ai1 > ai2 ? ai1 : ai2);
        }
    }

    for(auto i : ans){
        std::cout<<i<<' ';
    }

    std::cout<<'\n';

}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long curr;
    std::vector<long long>b;
    std::cin>>t;

    while(t--){
        b.clear();
        std::cin>>n;

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            b.push_back(curr);
        }

        solve(n,b);
    }

    return 0;
}