#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    cin>>n;
    vector<ll> c(5,0);
    vector<char> ch = {'a', 'e', 'i', 'o', 'u'};
    ll j = 0;
    for(long long i = 0; i<n; i++){
        j%=5;
        c[j]++;
        j++;
    }

    for(long long i = 0; i<5; i++){
        for(long long j = 0; j<c[i]; j++){
            cout<<ch[i];
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