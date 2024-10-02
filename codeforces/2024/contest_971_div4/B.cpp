#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    cin.ignore();
    vector<string> v(n);
    string s;
    for(long long i = 0; i<n; i++){
        getline(cin, s);

        v[i] = s;

    }

    for(long long i = n-1; i>=0; i--){
        for(long long j = 0; j<4; j++){
            if(v[i][j] == '#'){
                cout<< j+ 1<<' ';
            }
        }
    }

    cout<<'\n';
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