#include <bits/stdc++.h>

void solve(){
    long long n;
    long long m;
    long long ans = 0;
    long long k;
    long long curr;
    std::cin>>n;
    std::cin>>m;
    std::cin>>k;
    std::vector<long long>a;
    std::vector<long long>b;
    std::vector<long long>p(n+1, 0);
    std::map<long long, long long> bOcurrences;
    std::map<long long, long long>subSeqOcurrences;

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        a.push_back(curr);
    }

    for(long long i = 0; i<m; i++){
        std::cin>>curr;
        b.push_back(curr);

        if(bOcurrences.count(curr)){
            bOcurrences[curr]++;
        } else {
            bOcurrences[curr] =1;
        }
    }
    long long toSubstract = 0;
    for(long long i = 1; i<=n; i++){
        
        if(i-m >= 1){
            if(subSeqOcurrences.count(a[i-m-1])){
                if(bOcurrences.count(a[i-m-1])){
                    if(subSeqOcurrences[a[i-m-1]] > bOcurrences[a[i-m-1]]){
                        toSubstract--;
                    }
                }
                subSeqOcurrences[a[i-m-1]]--;
            }
        }

        if(bOcurrences.count(a[i-1])){
            if(subSeqOcurrences.count(a[i-1])){
                subSeqOcurrences[a[i-1]]++;
            } else {
                subSeqOcurrences[a[i-1]] = 1;
            }

            if(subSeqOcurrences[a[i-1]] > bOcurrences[a[i-1]]){
                toSubstract++;
            }

            p[i] = p[i-1] + 1;
        } else {
            p[i] = p[i-1];
        }

        if(i>=m){

            //i-m;
            if(p[i] - p[i-m] - toSubstract >= k){
                ans++;
            }
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