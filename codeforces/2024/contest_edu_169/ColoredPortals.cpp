#include <bits/stdc++.h>
#define ll long long

using namespace std;

void solve(){
    ll n;
    ll q;
    cin>>n>>q;
    vector<string> a(n);
    vector<pair<ll,ll>>c(n);
    map<string, string> ne;
    map<string, ll> occ;
    ne["BG"] = "RY";
    ne["BR"] = "GY";
    ne["BY"] = "GR";
    ne["GR"] = "BY";
    ne["GY"] = "BR";
    ne["RY"] = "BG";

    for(long long i = 0; i<n; i++){
        string curr;
        cin>>curr;
        c[i].first = -1;

        for(auto& e : occ){
            if(e.first != curr && e.first != ne[curr]) c[i].first = max(c[i].first, e.second);
        }

        occ[curr] = i;
        a[i] = curr;
    }
    occ.clear();
    for(long long i = n-1; i>=0; i--){
        c[i].second = n;
        for(auto& e : occ){
            if(e.first != a[i] && e.first != ne[a[i]]) c[i].second = min(c[i].second, e.second);
        }
        occ[a[i]] = i;
    }

    ll x;
    ll y;

    for(long long i = 0; i<q; i++){
        cin>>x>>y;
        x--;
        y--;
        if(x > y) swap(x,y);

        if(x < y){
            if(a[y] != ne[a[x]] || c[x].second < y){
                cout<<y-x<<'\n';
            } else {
                ll mn = 1e9;
                if(c[x].second != n) mn = min(mn, abs(c[x].second - x) + abs(y-c[x].second));
                if(c[x].first != -1) mn = min(mn, abs(c[x].first - x) + abs(c[x].first - y));

                cout<<(mn == 1e9 ? -1 : mn)<<'\n';
            }          
        } else {
            cout<<0<<'\n';
        }
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