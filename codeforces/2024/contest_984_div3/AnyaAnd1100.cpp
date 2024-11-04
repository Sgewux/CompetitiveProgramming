#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    cin.ignore();
    string s;
    getline(cin, s);
    ll n = s.length();
    ll q; cin>>q;

    ll cnt = 0;
    for(long long i = 0; i<n; i++){
        if(s[i] == '1'){
            string xd = "";
            for(long long j = 0; j<4; j++){
                if(i + j < n) xd.push_back(s[i+j]);
            }

            if(xd == "1100") cnt++;
        }
    }

    while(q--){
        ll i; ll v;
        cin>>i>>v;

        i--;
        
        if(n < 4){
            cout<<"NO"<<'\n';
        } else {
            string ne = s;
            ne[i] = (char)('0' + v);
            
            for(long long j = max((ll)0,i-3); j<=i; j++){
                string former = "";
                string neu = "";
                for(long long k = 0; k<4; k++){
                    if(j + k < n){
                        former.push_back(s[j+k]);
                        neu.push_back(ne[j+k]);
                    }
                }

                if(former != neu){
                    if(former == "1100") cnt--;
                    if(neu == "1100") cnt++;
                }
            }

            s[i] = (char)('0' + v);

            cout<<(cnt ? "YES" : "NO")<<'\n';

        }

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