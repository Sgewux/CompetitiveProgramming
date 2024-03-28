#include <bits/stdc++.h>

void solve(){
    std::string a;
    std::getline(std::cin, a);
    long long ans = 1e18;

    for(long long n = 0; n<=62; n++){
        std::string b = std::to_string((long long)std::pow(2,n));
        long long cantOfMoves = 0;
        long long i = 0;
        long long j = 0;

        while(i<a.length() && j<b.length()){
            if(a[i] != b[j]){
                cantOfMoves++;
                i++;
            } else {
                i++;
                j++;
            }
        }

        if( !(i==a.length() && j==b.length()) ){
            if(j<b.length()){
                cantOfMoves += b.length() - j;
            } else {
                cantOfMoves += a.length() - i;
            }
        }

        ans = std::min(ans, cantOfMoves);
   }

   std::cout<<ans<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;
    std::cin.ignore();

    while(t--){
        solve();
    }

    return 0;
}