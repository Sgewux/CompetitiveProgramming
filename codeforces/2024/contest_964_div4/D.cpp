#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    string s;
    string t;

    getline(cin, s);
    getline(cin, t);
    ll lens = s.length();
    ll lent = t.length();

    ll i = lens-1;
    ll j = lent-1;

    while(j >= 0 && i >= 0){
        if(s[i] == t[j]){
            j--;
        } else if(s[i]=='?'){
            s[i] = t[j];
            j--;
        }

        i--;
    }

    if(j >= 0){
        std::cout<<"NO"<<'\n';
        return;
    } else {
        cout<<"YES"<<'\n';
        for(auto& c : s){
            if(c == '?'){
                cout<<'x';
            } else {
                cout<<c;
            }
        }

        cout<<'\n';
    }
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