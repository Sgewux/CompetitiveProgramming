#include <bits/stdc++.h>

void solve(){
    long long n;
    long long f;
    long long k;

    std::cin>>n;
    std::cin>>f;
    std::cin>>k;

    std::vector<long long>a(n);

    for(long long i = 0; i<n; i++){
        std::cin>>a[i];
    }

    f = a[f-1];
    long long greater =0;
    long long smaller =0;
    long long equal = 0;

    for(long long i = 0; i<n; i++){
        if(a[i] < f){
            smaller++;
        } else if(a[i] > f){
            greater++;
        } else {
            equal++;
        }
    }

    if(k >= greater+equal){
        std::cout<<"YES"<<'\n';
    } else if(k >= greater + 1){
        std::cout<<"MAYBE"<<'\n';
    } else {
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