#include <bits/stdc++.h>

void solve(){
    long long n;
    long long k;
    std::cin>>n;
    std::cin>>k;
    std::map<long long, std::vector<long long>> m; //1st 2nd
    std::map<long long, long long> lastPos;
    std::vector<long long> c(n);

    for(long long i = 0; i<n; i++){
        std::cin>>c[i];
    }

    for(long long i = 0; i<n; i++){
        if(!lastPos.count(c[i])){
            m[c[i]].push_back(i);
        } else {
            long long currDis = i - lastPos[c[i]] -1;
            m[c[i]].push_back(currDis);
        }

        lastPos[c[i]] = i;
    }

    for(long long i = 1; i<=k; i++){
        long long currDis = n - lastPos[i] -1;
        m[i].push_back(currDis);
    }

    long long ans = 1e9;
    for(long long i = 1; i<=k; i++){
        std::sort(m[i].begin(), m[i].end());
        long long size = m[i].size();
        m[i][size-1] = (m[i][size-1] % 2 == 0 ? m[i][size-1]/2 : (m[i][size-1]-1)/2);
        std::sort(m[i].begin(), m[i].end());

        ans = std::min(ans, std::max(m[i][size-1],m[i][size-2]));
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