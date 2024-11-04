#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll m;
    cin>>n>>m;
    vector<string>mt(n);
    vector<string>v;
    cin.ignore();
    for(long long i = 0; i<n; i++){
        
        getline(cin, mt[i]);
        
    }

    ll a = 0;

    while(a < min(n,m)/2){
        string x = "";

        for(long long i = a; i<=m-1-a; i++){
            x.push_back(mt[a][i]);
        }

        for(long long i = a + 1; i<=n-1-a; i++){
            x.push_back(mt[i][m-1-a]);
        }

        for(long long i = m-2-a; i>=a; i--){
            x.push_back(mt[n-1-a][i]);
        }

        for(long long i = n-2-a; i>a; i--){
            x.push_back(mt[i][a]);
        }

        v.push_back(x);
        a++;
    }

    ll ans = 0;

    for(auto & s : v){
        ll ln = s.length();
        for(long long i = 0; i<ln; i++){
            if(s[i] == '1'){
                string xd = "1";
                for(long long j = 1; j<4; j++){
                    xd.push_back(s[(i + j) % ln]);
                }

                if(xd == "1543") ans++;
            }
        }
    }

    cout<<ans<<'\n';


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