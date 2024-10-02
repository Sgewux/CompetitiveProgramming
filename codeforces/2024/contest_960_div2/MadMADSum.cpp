#include <bits/stdc++.h>

void solve(){
    long long n;
    long long sum = 0;
    long long currMAD = 0;
    long long curr;
    std::map<long long, long long> m;
    std::cin>>n;
    std::vector<long long> a(n);

    for(long long i = 0; i<n; i++){
        std::cin>>curr;
        sum+=curr;
        m[curr]++;
        if(m[curr] >= 2 && curr>currMAD) currMAD = curr;

        a[i] = currMAD;
    }

    m.clear();
    currMAD = 0;
    for(long long i = 0; i<n; i++){
        sum+=a[i];
        m[a[i]]++;
        if(m[a[i]] >= 2 && a[i]>currMAD) currMAD = a[i];
        
        a[i] = currMAD;
    }

    for(long long i = 1; i<n; i++){
        a[i] += a[i-1];
    }

    for(long long i = n-1; i>=0; i--){
        sum += a[i];
    }

    std::cout<<sum<<'\n';
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