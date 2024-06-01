#include <bits/stdc++.h>

void solve(){
    long long n;
    std::cin>>n;
    std::vector<std::string> v(n);
    long long curr;
    std::map<std::string, long long> m;
    long long ans = 0;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        v[i] = std::to_string(curr);
    }

    for(long long i = 0; i<n-2; i++){
        std::string a = v[i];
        std::string b = v[i+1];
        std::string c = v[i+2];

        ans += m["0-" + b + "-" + c];
        ans += m[a + "-0-" + c];
        ans += m[a + "-" + b + "-0"];
        ans -= 3*m[a+ "-" +b + "-" +c];

        m["0-" + b + "-" + c]++;
        m[a + "-0-" + c]++;
        m[a + "-"+ b + "-0"]++;
        m[a+ "-" +b + "-" +c]++;
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