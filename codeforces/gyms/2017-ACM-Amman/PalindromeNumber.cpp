#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n; ll s;
    cin>>n>>s;
    if(!(n&1) && (s&1)){
        cout<<-1<<'\n';
        return;
    }

    string ans = "";
    ll ones = s/2;
    ll remainder = s & 1;

    while(ones && ans.length() < n/2){
        if(ones <= 9){
            ans.push_back(ones + '0');
            ones = 0;
        } else {
            ans.push_back('9');
            ones -= 9;
        }
    }

    if(ones){
        if((2*ones + remainder) > 9){
            cout<<-1<<'\n';
            return;
        } else {
            remainder += 2*ones;
        }
    }

    while(ans.length() < n/2) ans.push_back('0');

    if(ans.length() == n/2 && ans[0] != '0'){
        cout<<ans;
        reverse(ans.begin(), ans.end());
        if(n&1) cout<<remainder;
        cout<<ans<<'\n';
    } else {
        cout<<-1<<'\n';
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