#include <bits/stdc++.h>

void solve(){
    long long n;
    long long k;
    long long pb;
    long long ps;
    
    std::cin>>n;
    std::cin>>k;
    std::cin>>pb;
    std::cin>>ps;
    
    std::set<long long> visitedB;
    std::set<long long> visitedS;
    std::vector<long long>cycleB;
    std::vector<long long>cycleS;
    std::vector<long long> perm(n);
    std::vector<long long> a(n);



    for(long long i = 0; i<n; i++){
        std::cin>>perm[i];
    }

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
    }

    while(!visitedB.count(pb) && cycleB.size() <= k){
        visitedB.insert(pb);
        cycleB.push_back(a[pb-1]);
        pb = perm[pb-1];
    }

    while(!visitedS.count(ps) && cycleS.size() <= k){
        visitedS.insert(ps);
        cycleS.push_back(a[ps-1]);
        ps = perm[ps-1];
    }

    long long sasha = 0;
    long long bodya = 0;
    long long currSum = 0;
    long long currMax = 0;

    for(long long i = 0; i<cycleB.size(); i++){
        currMax = std::max(currMax, cycleB[i]);
        currSum += cycleB[i];
        bodya = std::max(bodya, currSum + (k -(i+1))*currMax);
    }

    currMax = 0;
    currSum = 0;
    
    for(long long i = 0; i<cycleS.size(); i++){
        currMax = std::max(currMax, cycleS[i]);
        currSum += cycleS[i];
        sasha = std::max(sasha, currSum + (k -(i+1))*currMax);
    }

    if(sasha > bodya){
        std::cout<<"Sasha";
    } else if(bodya > sasha){
        std::cout<<"Bodya";
    } else {
        std::cout<<"Draw";
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