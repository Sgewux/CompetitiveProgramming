#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll suma = 0;
    cin>>n;
    vector<ll>a(n);

    for(long long i = 0; i<n; i++){
        cin>>a[i];
        suma += a[i];
    }

    ll m1;
    cin>>m1;
    cin.ignore();


    for(long long i = 0; i<m1; i++){
        map<char,ll> m;
        map<ll, char> m2;
        string s;
        getline(cin, s);
        ll j = 0;
        if(s.length() == n){
            bool si = true;
            for(auto& c : s){
                if(m.count(c)){
                    if(m[c] != a[j]){
                        si = false;
                    }
                } else {
                    if(m2.count(a[j])){
                        si = false;
                    } else {
                        m2[a[j]] = c;
                        m[c] = a[j];
                    }
                }
                j++;
            }
            cout<<(si ? "YES" : "NO")<<'\n';
        } else {
            cout<<"NO"<<'\n';
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