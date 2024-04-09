#include <bits/stdc++.h>

void solve(){
    long long n;
    long long curr;
    long long outsider;
    std::set<long long>present;
    std::set<long long>perm;
    std::vector<long long>missing;
    std::cin>>n;

    std::vector<long long> p(n+1,0);

    for(long long i = 1; i<n; i++){
        perm.insert(i);
        std::cin>>curr; 
        p[i]  = curr;

        if(p[i] - p[i-1] > n){
            outsider = p[i]-p[i-1];
        } else {
            if(present.count(p[i] - p[i-1])){
                outsider = p[i] - p[i-1];
            } else {
                present.insert(p[i] - p[i-1]);
            }
        }
    }

    perm.insert(n);

    if(present.size() == n-1){
        std::cout<<"YES"<<'\n';
    } else if(present.size() == n-2){
        std::set_symmetric_difference(
            perm.begin(), perm.end(),
            present.begin(), present.end(),
            std::inserter(missing, missing.begin())
        );

        for(long long i = 1; i<n; i++){
            if(p[i] - p[i-1] == outsider){
                if(missing[0]+p[i-1] == p[i] - missing[1] || missing[1]+p[i-1] == p[i]-missing[0]){
                    std::cout<<"YES"<<'\n';
                    return;
                }
            }
        }

        std::cout<<"NO"<<'\n';
    }else {
        std::cout<<"NO"<<'\n';
    }
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