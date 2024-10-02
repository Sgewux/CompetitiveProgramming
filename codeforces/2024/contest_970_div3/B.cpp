#include <bits/stdc++.h>
#define ll long long

using namespace std;

bool perfect(ll n){
    ll i = 0;
    while(i*i <= n){
        if((i*i) == n){
            return true;
        }
        i++;
    }

    return false;
}

void solve(){
    ll n;
    cin>>n;
    cin.ignore();
    string s;
    getline(cin, s);

    if(perfect(n)){
        ll sq = sqrt(n);
        vector<string> v;

        ll i = 0;

        while(i < s.length()){
            v.push_back(s.substr(i, sq));
            i += sq;
        }

        for(long long i = 0; i<sq; i++){
            if(i == 0 || i == sq-1){
                ll z = 0;
                for(auto& c : v[i]){
                    if(c == '0') z++;
                }

                if(z > 0){
                    cout<<"No"<<'\n';
                    return;
                }
            } else {
                if(v[i][0] && v[i][sq-1] == '1'){
                    string si = v[i].substr(1,sq-2);
                    ll z = 0;
                    for(auto& c : si){
                        if(c == '1') z++;
                    }

                    if(z > 0){
                        cout<<"No"<<'\n';
                        return;
                    }

                } else {
                    cout<<"No"<<'\n';
                    return;
                }
            }
        }

    } else {
        cout<<"No"<<'\n';
        return;
    }

    cout<<"Yes"<<'\n';
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