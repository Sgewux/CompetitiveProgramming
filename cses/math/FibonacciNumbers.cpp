#include <bits/stdc++.h>
#define ll long long

using namespace std;
const ll m = 1e9 + 7;

vector<vector<ll>> mul(vector<vector<ll>>& a, vector<vector<ll>>& b){
    vector<vector<ll>> c = {{0,0}, {0,0}};
    for(long long i = 0; i<2; i++){
        for(long long j = 0; j<2; j++){
            for(long long k = 0; k<2; k++){
                c[i][j] += (a[i][k] * b[k][j]) % m;
                if(c[i][j] >= m) c[i][j] -= m;
            }
        }
    }

    return c;
}

vector<vector<ll>> binexpo(vector<vector<ll>>& a, ll b){
    if(b == 0) return {{1,0},{0,1}};
    vector<vector<ll>> res = binexpo(a,b/2);
    res = mul(res, res);
    
    if(b & 1){
        return mul(res,a);
    } else {
        return res;
    }
}

void solve(){
    ll n;
    cin>>n;
    if(n == 0){
        cout<<0;
    } else if(n == 1){
        cout<<1;
    } else {
        vector<vector<ll>> m = {{1,1}, {1,0}};
        m = binexpo(m, n-1);
        cout<<m[0][0];
    }
   
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