#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    string ans = "";
    bool end = false;

    while(ans.length() < n){
        int qans;
        if(end){
            ans += "0";
            cout<<"? "<<ans<<endl;
            cin>>qans;
            if(qans) continue;
            ans.pop_back();
            ans += "1";

        } else {
            ans = "0" + ans;
            cout<<"? "<<ans<<endl;
            cin>>qans;

            if(qans) continue;
            ans[0] = '1';
            cout<<"? "<<ans<<endl;
            cin>>qans;
            if(!qans) {
                end = true;
                ans = ans.substr(1,ans.length() - 1);
            }
           
        }
    }

    cout<<"! "<< ans <<endl;
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