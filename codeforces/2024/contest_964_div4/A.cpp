#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    std::string s;
    std::getline(cin, s);

    cout<<((ll)(s[0]-48) + (ll)(s[1]-48))<<'\n';
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t;
    std::cin>>t;
    cin.ignore();

    while(t--){
        solve();
    }

    return 0;
}