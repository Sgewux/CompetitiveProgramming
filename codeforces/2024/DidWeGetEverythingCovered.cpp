#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n; ll k; ll m; string s;
    string ans = "";
    cin>>n>>k>>m;
    cin.ignore();
    getline(cin, s);
    set<char>seen;
    for(long long j = 0; j<m; j++){
        if(ans.length() == n) break;
        if(!seen.count(s[j])) seen.insert(s[j]);
        if(seen.size() == k){
            ans+=s[j];
            seen.clear();
        }
    }

    if(ans.length() == n){
        cout<<"YES"<<'\n';
    } else {
        for(long long i = 0; i<k; i++){
            if(!seen.count('a' + i)){
                while(ans.length() < n) ans += ('a' + i);
            }
        }

        cout<<"NO"<<'\n';
        cout<<ans<<'\n';
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