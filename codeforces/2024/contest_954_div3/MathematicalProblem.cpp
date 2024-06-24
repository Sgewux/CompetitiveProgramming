#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin>>n;
    std::cin.ignore();
    std::string s;
    std::getline(std::cin, s);
    std::vector<long long> v(n);
    long long ones = 0;
    long long zeros = 0;
    long long sum = 0;

    for(long long i = 0; i<n; i++){
        long long curr = s[i] - 48;
        if(curr == 1){
            ones++;
        }
        if(curr == 0){
            zeros++;
        }

        v[i] = curr;
        sum+= curr;
    }

    if(zeros > 0 && n > 3){
        std::cout<<0<<'\n';
        return;
    } else if(n == 2){
        std::cout<<std::stoi(s)<<'\n';
        return;
    } else if (n == 3){
        if(v[0] == 0 || v[2] == 0){
            std::cout<<0<<'\n';
            return;
        }

    }

    long long ans = 2e9;

    for(long long i = 0; i<n-1; i++){
        long long currDigit = v[i]*10 + v[i+1];
        long long currOnes = 0;

        if(v[i] == 1){
            currOnes ++;
        }

        if(v[i+1] == 1){
            currOnes++;
        }

        if(currDigit == 1){
            ans = std::min(ans, sum-ones > 0 ? sum-ones : 1);
        } else {
            ans = std::min(ans, sum-v[i]-v[i+1]+currDigit-(ones-currOnes));
        }

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