#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll mx = -1;
    cin>>n;
    vector<ll>m(1e6+1, -1);
    vector<ll>ones;

    for(long long i = 1; i<=n; i++){
        ll curr;
        cin>>curr;
        mx = max(mx, curr);
        m[curr] = i;
        if(curr == 1) ones.push_back(i);
    }
    
    if(ones.size() >= 2){
        cout<<ones[0]<<' '<<ones[1]<<'\n';
        return;
    }

    ll a = 1;
    ll b = 2;

    while(a <= mx){
        if(m[a] != -1 && m[b] != -1){
           cout<<m[a] << ' '<<m[b]<<'\n';
           return;
        }

        ll temp = a;
        a = b;
        b = temp + b;
    }

    cout<<"impossible"<<'\n';
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