#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n; ll k;
    cin>>n>>k;
    cin.ignore();
    string s;
    getline(cin, s);
    vector<int>m;

    for(auto& c : s) m.push_back(c == 'R');
    ll cnt = 0;
    int g = 0;

    for(long long i = 0; i<n; i++){
        if(m[i] != g){
            cnt++;
        } else {
            g = !g;
        }
    }

    cout<<max((ll)0, k-cnt);
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t=1;

    while(t--){
        solve();
    }

    return 0;
}  