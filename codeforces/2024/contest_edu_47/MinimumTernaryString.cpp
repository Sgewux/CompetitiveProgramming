#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    string s;
    string a;
    string b;
    getline(cin, s);
    bool t = false;

    for(auto & c : s){
        if(c == '2') t = true;
        if(t && (c == '2' || c == '0')) {
            b.push_back(c);
        } else {
            a.push_back(c);
        }
    }

    sort(a.begin(), a.end());
    cout<< a+b;
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