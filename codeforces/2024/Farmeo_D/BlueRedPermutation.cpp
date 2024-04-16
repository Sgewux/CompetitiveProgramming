#include <bits/stdc++.h>

void solve(long long n, std::vector<long long>& nums, std::string& colors){

    std::vector<long long> reds;
    std::vector<long long> blues;

    for(long long i = 0; i<n; i++){
        if(colors[i] == 'R'){
            reds.push_back(nums[i]);
        } else {
            blues.push_back(nums[i]);
        }
    }

    std::sort(reds.begin(), reds.end(), std::greater<>());
    std::sort(blues.begin(), blues.end());

    for(long long i = 0; i<blues.size(); i++){
        if(i + 1 > blues[i] || blues[i] < 1){
            std::cout<<"NO";
            return;
        }
    }

    for(long long i = 0; i<reds.size(); i++){
        if(i + 1 > (n -reds[i] + 1) || reds[i] > n){
            std::cout<<"NO";
            return;
        }
    }

    std::cout<<"YES";
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    long long n;
    long long curr;
    std::string colors;
    std::cin>>t;

    while(t--){
        std::cin>>n;
        std::vector<long long> nums;

        for(long long i = 0; i<n; i++){
            std::cin>>curr;
            nums.push_back(curr);
        }

        std::cin.ignore();
        std::getline(std::cin, colors);

        solve(n, nums, colors);
        std::cout<<'\n';
    }

    return 0;
}