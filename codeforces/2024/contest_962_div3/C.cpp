#include <bits/stdc++.h>

void solve(){
    long long n;
    long long q;
    std::cin>>n>>q;
    std::cin.ignore();
    std::string a;
    std::string b;
    std::getline(std::cin, a);
    std::getline(std::cin, b);

    std::vector<std::vector<long long>> pa(26,std::vector<long long>(n+1,0));
    std::vector<std::vector<long long>> pb(26,std::vector<long long>(n+1,0));

    for(long long i = 0; i<n; i++){
        pa[a[i]-97][i+1]++;
    }

    for(long long i = 0; i<n; i++){
        pb[b[i]-97][i+1]++;
    }

    for(long long i = 0; i<26; i++){
        for(long long j = 1; j<=n; j++){
            pa[i][j] = pa[i][j-1] + pa[i][j];
            pb[i][j] = pb[i][j-1] + pb[i][j];
        }
    }

    for(long long i = 0; i<q; i++){
        long long l;
        long long r;
        std::cin>>l>>r;
        std::vector<long long> charsA(26);
        std::vector<long long> charsB(26);
        long long ansA = 0;
        long long ansB = 0;

        for(long long i = 0; i<26; i++){
            charsA[i] = pa[i][r] - pa[i][l-1];
        }
        for(long long i = 0; i<26; i++){
            charsB[i] = pb[i][r] - pb[i][l-1];
        }

        for(long long i = 0; i<26; i++){
            if(charsB[i] > charsA[i]){
                ansA += charsB[i] - charsA[i];
            }
            if(charsA[i] > charsB[i]){
                ansB += charsA[i] - charsB[i];
            }
        }

        std::cout<<std::min(ansA, ansB)<<'\n';
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