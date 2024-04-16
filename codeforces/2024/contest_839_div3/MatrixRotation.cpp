#include <bits/stdc++.h>

void solve(){
    std::vector<std::vector<long long>> m;
    long long curr;
    m.push_back({0,0});
    m.push_back({0,0});

    for(long long i = 0; i<2; i++){
        std::cin>>curr;
        m[0][i] = curr;
    }

    for(long long i = 0; i<2; i++){
        std::cin>>curr;
        m[1][i] = curr;
    }

    bool a = m[0][0] < m[0][1] && m[1][0] < m[1][1] && m[0][0] < m[1][0] && m[0][1] < m[1][1];
    bool b = m[1][0] < m[0][0] && m[1][1] < m[0][1] && m[1][0] < m[1][1] && m[0][0] < m[0][1];
    bool c = m[1][1] < m[1][0] && m[0][1] < m[0][0] && m[1][1] < m[0][1] && m[1][0] < m[0][0];
    bool d = m[0][1] < m[1][1] && m[0][0] < m[1][0] && m[0][1] < m[0][0] && m[1][1] < m[1][0];

    if(a||b||c||d){
        std::cout<<"YES";
    } else {
        std::cout<<"NO";
    }

    std::cout<<'\n';
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