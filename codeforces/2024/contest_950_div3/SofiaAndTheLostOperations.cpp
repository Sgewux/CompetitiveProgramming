#include <bits/stdc++.h>

void solve(){
    long long n;
    long long m;
    std::cin>>n;
    std::vector<long long>a(n);
    std::vector<long long>b(n);

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
    }

    std::set<long long> bElems;
    for(long long i = 0; i<n; i++){
        std::cin>>b[i];
        bElems.insert(b[i]);
    }

    std::cin>>m;
    std::vector<long long>d(m);
    std::map<long long, long long>dCnt;

    for(long long i = 0; i<m; i++){
        std::cin>>d[i];
        dCnt[d[i]]++;
    }

    std::map<long long, long long> diffCnt;

    for(long long i = 0; i<n; i++){
        if(a[i] != b[i]){
            diffCnt[b[i]]++;
        }
    }

    for(auto& e : diffCnt){
        if(!dCnt.count(e.first) ||  dCnt[e.first] < e.second){
            std::cout<<"NO"<< '\n';
            return;
        }
    }

    bool belongs = true;
    for(long long i = 0; i<m; i++){
        if(bElems.count(d[i])){
            belongs= true;
        } else {
            belongs = false;
        }
    }

    std::cout<<(belongs ? "YES" : "NO")<<'\n';
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