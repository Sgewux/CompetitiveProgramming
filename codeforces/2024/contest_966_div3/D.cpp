#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll curr;
    cin>>n;
    vector<ll>p(n+1,0);

    for(long long i = 1; i<=n; i++){
        cin>>curr; 
        p[i] = p[i-1] + curr;
    }

    cin.ignore();
    string s;
    getline(cin, s);

    ll l = 1;
    ll r = n;
    ll ans = 0;

    while(l < r){
        if(s[l-1] == 'L' && s[r-1] == 'R'){
            ans += p[r] - p[l-1];
            l++;
            r--;
            continue;
        }

        if(s[l-1] != 'L') l++;
        if(s[r-1] != 'R') r--;
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