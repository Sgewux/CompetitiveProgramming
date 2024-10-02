#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n;
set<int> w;

void check(vector<pair<int,int>> a, vector<pair<int,int>> b, vector<pair<int,int>> c){
    int minB = 1e9 + 1;
    int minC = 1e9 + 1;
    sort(a.begin(), a.end(), greater<pair<int,int>>());
    for(long long j = n-1; j>=0; j--){
        int i = a[j].second;
        if(b[i].first > minB || c[i].first > minC) w.insert(i+1);
        minB = min(minB, b[i].first);
        minC = min(minC, c[i].first);
    }
}

void solve(){
    cin>>n;
    vector<pair<int,int>> a(n);
    vector<pair<int,int>> b(n);
    vector<pair<int,int>> c(n);
    for(long long i = 0; i<n; i++){
        cin>>a[i].first>>b[i].first>>c[i].first;
        a[i].second = i;
        b[i].second = i;
        c[i].second = i;
    }

    check(a,b,c);
    check(b,a,c);
    check(c,a,b);

    cout<<n - w.size()<<'\n';
    for(long long i = 1; i<=n; i++){
        if(!w.count(i)) cout<< i <<'\n';
    }
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