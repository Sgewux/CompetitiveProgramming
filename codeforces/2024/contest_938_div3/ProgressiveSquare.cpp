#include <bits/stdc++.h>

void solve(){
    long long n;
    long long c;
    long long d;
    long long curr;
    long long a1 = 2e9;
    std::map<long long, long long> mi;
    std::map<long long, long long>mc;
    std::cin>>n;
    std::vector<std::vector<long long>>s;
    std::cin>>c;
    std::cin>>d;

    for(long long i = 0; i<n*n; i++){
        std::cin>>curr;
        a1 = std::min(a1, curr);
        if(mi.count(curr)){
            mi[curr]++;
        } else {
            mi[curr] = 1;
        }
    }

    for(long long i = 0; i<n; i++){
        std::vector<long long> xd(n,0);
        s.push_back(xd);
    }

    for(long long i = 0; i<n; i++){
        if(i==0){
            s[0][0] = a1;
        } else {
            s[i][0] = s[i-1][0] + c;
        }

        if(mc.count(s[i][0])){
            mc[s[i][0]]++;
        } else {
            mc[s[i][0]] = 1;
        }


        for(long long j = 1; j<n; j++){

            s[i][j] = s[i][j-1] + d;

            if(mc.count(s[i][j])){
                mc[s[i][j]]++;
            } else {
                mc[s[i][j]] = 1;
            }
        }

    }

    bool ans = true;

    for(auto& kv : mc){
        if( !(mi.count(kv.first) && mi[kv.first] == kv.second)){
            ans = false;
        }
    }

    if(ans){
        std::cout<<"YES";
    } else {
        std::cout<< "NO";
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