#include <bits/stdc++.h>
#define ll long long

using namespace std;
bool found = false;
string s;

bool check(string m, ll n){
    ll state = 0;
    
    for(auto& c : m){
        state = (2* state + (c == '1' ? 1 : 0)) % n;
    }

    return (state == 0);
}

void f(ll i, ll j, ll k){
    if(found) return;
    
    if(i == (j + k)){
        ll n = 0;
        for(auto& c : s.substr(j,k)){
            n = (2* n + (c == '1' ? 1 : 0));
        }
        
        if(check(s.substr(0,j), n) && !found) {
            cout<<s.substr(0,j);
            found = true;
        }
        
        return;
        
    } else {
        if(s[i] == '*'){
            s[i] = '0';
            f(i+1, j, k);
            s[i] = '1';
            f(i+1, j, k);
            s[i] = '*';
        } else {
            f(i+1, j, k);
        }
    }
}

void solve(){
    string m;
    string n;
    
    getline(cin, m);
    getline(cin, n);
    s = m+n;
    
    f(0, m.length(), s.length());
}

int main(){
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    long long t = 1;

    while(t--){
        solve();
    }

    return 0;
}